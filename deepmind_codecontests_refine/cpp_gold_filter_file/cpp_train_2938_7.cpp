#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 110;
const int M = 1e9 + 7;
int n, m, k, t;
multiset<string> st;
string ans = " ";
string f[maxn];
int main() {
  scanf("%d", &n);
  cout << "? 1 " << n << endl;
  fflush(stdout);
  for (int i = 1; i <= n; i++) {
    for (int j = i; j <= n; j++) {
      string tmp;
      cin >> tmp;
      sort(tmp.begin(), tmp.end());
      st.insert(tmp);
    }
  }
  if (n == 1) {
    cout << "! " << *st.begin() << endl;
    return 0;
  }
  cout << "? 2 " << n << endl;
  fflush(stdout);
  for (int i = 2; i <= n; i++) {
    for (int j = i; j <= n; j++) {
      string tmp;
      cin >> tmp;
      sort(tmp.begin(), tmp.end());
      st.erase(st.find(tmp));
    }
  }
  for (auto tmp : st) {
    f[tmp.size()] = tmp;
  }
  ans += f[1];
  int mark[30];
  for (int j = 2; j <= n; j++) {
    memset(mark, 0, sizeof(mark));
    for (auto i : f[j]) {
      mark[i - 'a']++;
    }
    for (auto i : ans) {
      mark[i - 'a']--;
    }
    for (int i = 0; i < 30; i++) {
      if (mark[i]) ans += char(i + 'a');
    }
  }
  cout << "!" << ans << endl;
  return 0;
}
