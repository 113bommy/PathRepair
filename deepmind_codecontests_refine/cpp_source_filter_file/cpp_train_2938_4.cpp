#include <bits/stdc++.h>
using namespace std;
inline int read() {
  char c = getchar();
  int x = 0, f = 1;
  for (; !isdigit(c); c = getchar())
    if (c == '-') f = -1;
  for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
  return x * f;
}
int buca[300], bucb[300];
string v[300];
multiset<string> S;
inline char cmp(string a, string b) {
  memset(buca, 0, sizeof(buca));
  memset(bucb, 0, sizeof(bucb));
  for (int i = 0; i < a.size(); i++) buca[a[i]]++;
  for (int i = 0; i < b.size(); i++) bucb[b[i]]++;
  for (int i = 0; i < 300; i++)
    if (bucb[i] > buca[i]) return i;
}
int main() {
  int N = read();
  if (N == 1) {
    cout << "? 1 1\n";
    fflush(stdout);
    char c;
    cin >> c;
    cout << "! " << c << endl;
    fflush(stdout);
    return 0;
  }
  cout << "? 1 " << N << '\n';
  fflush(stdout);
  int Q = N * (N + 1) / 2;
  for (int i = 1; i <= Q; i++) {
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    S.insert(s);
  }
  cout << "? 2 " << N << '\n';
  fflush(stdout);
  Q = N * (N - 1) / 2;
  for (int i = 1; i <= Q; i++) {
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    auto it = S.lower_bound(s);
    S.erase(it);
  }
  int sz = 0;
  for (auto it = S.begin(); it != S.end(); it++) v[++sz] = *it;
  sort(v + 1, v + sz + 1,
       [&](string a, string b) { return a.size() < b.size(); });
  string ans = "";
  for (int i = 1; i <= sz; i++)
    if (i == 1)
      ans += v[i][0];
    else
      ans += cmp(v[i - 1], v[i]);
  cout << ans << endl;
  fflush(stdout);
  return 0;
}
