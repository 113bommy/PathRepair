#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int count = 0;
    for (int i = 0; i < n - 1; i++) {
      if (s[i] == 'R' && s[i + 1] == 'U' || s[i] == 'U' && s[i + 1] == 'R') {
        count++;
        i++;
      }
    }
    cout << n - count;
    cout << endl;
  }
  return 0;
}
