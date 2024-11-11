#include <bits/stdc++.h>
using namespace std;
void solve();
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  while (t--) {
    solve();
    cout << "\n";
  }
  cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
  return 0;
}
void solve() {
  string s;
  getline(cin, s);
  string v = "aeiouAEIOU";
  int index = 0;
  for (int i = s.length() - 1; i >= 0; i--) {
    if (isalpha(s[i])) {
      index = i;
      break;
    }
  }
  if (find(v.begin(), v.end(), s[index]) != v.end())
    cout << "YES";
  else
    cout << "NO";
}
