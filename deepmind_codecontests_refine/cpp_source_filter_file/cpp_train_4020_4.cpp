#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> > a;
int x, y;
int cnt = 0;
bool chck(int z) {
  int sum = 0, tmp = 0, c;
  for (int i = 0; i <= z; ++i) {
    sum += a[i].second - a[i].first + 1;
    if ((a[i].second - a[i].first + 1) % 2) {
      tmp ^= x;
    }
  }
  printf("? %d ", sum);
  for (int i = 0; i <= z; ++i) {
    for (int j = a[i].first; j <= a[i].second; ++j) {
      printf("%d ", j);
    }
  }
  fflush(stdout);
  scanf("%d", &c);
  return tmp != c;
}
bool chck2(int z, int v) {
  int sum = 0, tmp, c;
  sum = v - z + 1;
  if (sum % 2)
    tmp = x;
  else
    tmp = 0;
  printf("? %d ", sum);
  for (int j = z; j <= v; ++j) {
    printf("%d ", j);
  }
  fflush(stdout);
  scanf("%d", &c);
  return tmp != c;
}
int main() {
  int n, c, sum, tmp;
  cin >> n;
  vector<int> v, v1, prnt;
  a.clear();
  cin >> x >> y;
  cnt = 1;
  if (n < 19) {
    for (int i = 1; i <= n; ++i) {
      cout << "? 1 " << i << endl;
      fflush(stdout);
      cin >> c;
      if (c == y) v.push_back(i);
    }
    cout << "! " << v[0] << " " << v[1] << endl;
    fflush(stdout);
  } else {
    v.push_back(1);
    v.push_back(n);
    while (1) {
      prnt.clear();
      v1.clear();
      tmp = 0;
      sum = 0;
      for (int i = 0; i < v.size(); i += 2) {
        c = (v[i] + v[i + 1]) / 2;
        v1.push_back(v[i]);
        v1.push_back(c);
        v1.push_back(min(c + 1, n));
        v1.push_back(v[i + 1]);
        sum += c - v[i] + 1;
        for (int j = v[i]; j <= c; ++j) {
          prnt.push_back(j);
          if ((c - v[i] + 1) % 2) {
            tmp ^= x;
          }
        }
      }
      v = v1;
      v1.clear();
      cout << "? ";
      cout << prnt.size() << " ";
      for (int i = 0; i < prnt.size(); ++i) {
        cout << prnt[i] << " ";
      }
      fflush(stdout);
      cin >> c;
      if (c != tmp) {
        break;
      }
    }
    for (int i = 0; i < v.size(); i += 4) {
      a.push_back(make_pair(v[i], v[i + 1]));
    }
    int st = 0, nd = (int)(a.size()) - 1, md;
    while (st < nd) {
      md = (st + nd) / 2;
      if (chck(md)) {
        nd = md;
      } else {
        st = md + 1;
      }
    }
    int nnd = nd, sst = st;
    st = a[nd].first;
    nd = a[nd].second;
    while (st < nd) {
      md = (st + nd) / 2;
      if (chck2(st, md)) {
        nd = md;
      } else {
        st = md + 1;
      }
    }
    int ans1 = nd;
    st = a[nnd].second + 1;
    if (nnd == (int)(a.size()) - 1) {
      nd = n;
    } else {
      nd = a[nnd + 1].second;
    }
    while (st < nd) {
      md = (st + nd) / 2;
      if (chck2(st, md)) {
        nd = md;
      } else {
        st = md + 1;
      }
    }
    cout << "! " << ans1 << " " << nd << endl;
    fflush(stdout);
  }
  return 0;
}
