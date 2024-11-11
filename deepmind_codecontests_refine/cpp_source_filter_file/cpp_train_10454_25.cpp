#include <bits/stdc++.h>
using namespace std;
const int kMaxN = 105, inf = 1000000001;
int st[kMaxN], dr[kMaxN], a[kMaxN], n[kMaxN], an[kMaxN], na[kMaxN], nn[kMaxN],
    aa[kMaxN];
void v_join(vector<int> &rez, int plus, int dr, int n) {
  if ((n & 1) == 1) {
    for (int i = 0; i <= n / 2; ++i) rez.push_back(i + plus);
  } else {
    int c = 0;
    if (dr == 1)
      c = n / 2;
    else
      c = (n / 2) - 1;
    for (int i = 0; i <= c; ++i) rez.push_back(i + plus);
  }
}
vector<int> solve(int st, int dr, int n) {
  vector<int> rez;
  if (n == 1) {
    rez.push_back(0);
    return rez;
  }
  if (n == 2 and st == 0 and dr == 1) {
    rez.push_back(1);
    return rez;
  }
  if (st == 0) {
    v_join(rez, 1, dr, n - 2);
    v_join(rez, 0, dr, n - 2);
  } else {
    v_join(rez, 0, dr, n - 1);
  }
  sort(rez.begin(), rez.end());
  rez.resize(unique(rez.begin(), rez.end()) - rez.begin());
  return rez;
}
void show(int st, int dr, int n, int nr) {
  char leg[3] = {'A', 'C', 'B'};
  char rez[kMaxN];
  rez[0] = leg[dr];
  rez[n - 1] = leg[dr];
  if (n <= 2) {
    for (int i = 0; i < n; ++i) cout << rez[i];
    cout << '\n';
    return;
  }
  for (int i = 1; i + 1 < n; ++i) rez[i] = 'X';
  int start = 0;
  if (st != 0) start = 1;
  for (int i = start; nr; i += 2) {
    rez[i] = 'A';
    rez[i + 1] = 'C';
    --nr;
  }
  for (int i = 0; i < n; ++i) cout << rez[i];
  cout << '\n';
  return;
}
void low(int &a) {
  if (a >= inf) a = inf;
}
int main() {
  int k, x, A, B;
  cin >> k >> x >> A >> B;
  st[1] = 0;
  dr[1] = 0;
  a[1] = 1;
  n[1] = 0;
  st[2] = 1;
  dr[2] = 1;
  a[2] = 0;
  n[2] = 1;
  for (int i = 3; i <= k; ++i) {
    st[i] = st[i - 2];
    dr[i] = dr[i - 1];
    a[i] = a[i - 1] + a[i - 2];
    n[i] = n[i - 1] + n[i - 2];
    an[i] = an[i - 1] + an[i - 2];
    na[i] = na[i - 1] + na[i - 2];
    nn[i] = nn[i - 1] + nn[i - 2];
    aa[i] = aa[i - 1] + aa[i - 2];
    if (dr[i - 2] == 0 and st[i - 1] == 1) an[i]++;
    if (dr[i - 2] == 1 and st[i - 1] == 0) na[i]++;
    if (dr[i - 2] == 0 and st[i - 1] == 0) aa[i]++;
    if (dr[i - 2] == 1 and st[i - 1] == 1) nn[i]++;
    low(nn[i]);
    low(aa[i]);
    low(an[i]);
    low(na[i]);
    low(a[i]);
    low(n[i]);
  }
  for (int st1 = 0; st1 < 3; ++st1)
    for (int dr1 = 0; dr1 < 3; ++dr1)
      for (int st2 = 0; st2 < 3; ++st2)
        for (int dr2 = 0; dr2 < 3; ++dr2) {
          if (A == 1) st1 = dr1;
          if (B == 1) st2 = dr2;
          long long rez = 0;
          vector<int> mid1, mid2;
          mid1 = solve(st1, dr1, A);
          mid2 = solve(st2, dr2, B);
          for (vector<int>::iterator it1 = (mid1).begin(); it1 != (mid1).end();
               ++it1)
            for (vector<int>::iterator it2 = (mid2).begin();
                 it2 != (mid2).end(); ++it2) {
              rez = 0;
              rez += 1LL * (*it1) * a[k];
              rez += 1LL * (*it2) * n[k];
              if (dr1 == 0 and st2 == 1) rez += 1LL * an[k];
              if (dr1 == 0 and st1 == 1) rez += 1LL * aa[k];
              if (dr2 == 0 and st1 == 1) rez += 1LL * na[k];
              if (dr2 == 0 and st2 == 1) rez += 1LL * nn[k];
              if (rez == x) {
                show(st1, dr1, A, (*it1));
                show(st2, dr2, B, (*it2));
                return 0;
              }
            }
        }
  cout << "Happy new year!\n";
  return 0;
}
