#include <bits/stdc++.h>
using namespace std;
const long long oo = 2e9, mod = 1000000007;
int main() {
  cin.sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  map<string, string> my, my2;
  string tmp, tmp2;
  for (int i = 0; i < (int)m; i++) {
    cin >> tmp;
    cin >> tmp2;
    my[tmp] = tmp2;
    my[tmp2] = tmp;
  }
  string word;
  for (int i = 0; i < (int)n; i++) {
    cin >> word;
    if (my[word] != "") {
      if (word.size() <= my[word].size()) {
        cout << word;
      } else {
        cout << my[word];
      }
    } else {
      if (word.size() < my2[word].size()) {
        cout << word;
      } else {
        cout << my2[word];
      }
    }
    if (i < n - 1) {
      cout << " ";
    }
  }
  cout << endl;
  return 0;
}
