#include <bits/stdc++.h>
using namespace std;
const int N = 1000007, inf = 0x3f3f3f3f;
char S[N];
int main() {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  set<int> s;
  for (int i = 1; i <= N; ++i) s.insert(i);
  for (int i = 0; i < n; ++i) {
    string t;
    cin >> t;
    int m;
    cin >> m;
    for (int j = 0; j < m; ++j) {
      int a;
      cin >> a;
      int cur = a;
      while (1) {
        int p = *s.lower_bound(cur);
        if (p - a >= t.size()) break;
        cur = p;
        s.erase(cur);
        S[cur] = t[cur - a];
      }
    }
  }
  int l = 0;
  for (int i = 0; i < N; ++i)
    if (S[i]) l = i;
  for (int i = 1; i <= l; ++i) {
    if (S[i])
      cout << S[i];
    else
      cout << 'a';
  }
  cout << endl;
  return 0;
}
