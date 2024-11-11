#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<char> dir(n);
  for (int i = 0; i < n; i++) cin >> dir[i];
  vector<int> len(n);
  for (int i = 0; i < n; i++) cin >> len[i];
  int j = 0;
  for (int i = 0; i < n;) {
    if (j > n) {
      break;
    }
    if (dir[i] == '>') {
      i += len[i];
    } else if (dir[i] == '<') {
      i -= len[i];
      if (i == 0) {
        cout << "INFINTE\n";
        return 0;
      }
    }
    if (i >= n || i < 0) {
      cout << "FINITE\n";
      return 0;
    }
    j++;
  }
  cout << "INFINTE\n";
  return 0;
}
