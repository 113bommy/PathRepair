#include <bits/stdc++.h>
using namespace std;
int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);
  string st;
  int n;
  cin >> st >> n;
  if (n > st.length()) {
    cout << "impossible";
    return 0;
  }
  bool mark[26]{};
  for (char& c : st) mark[c - 'a'] = 1;
  int cnt = 0;
  for (int i = 0; i < 26; ++i) cnt += mark[i];
  cout << max(0, n - cnt);
}
