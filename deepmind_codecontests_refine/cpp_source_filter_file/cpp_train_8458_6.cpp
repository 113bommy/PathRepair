#include <bits/stdc++.h>
using namespace std;
int main() {
  int t = 0;
  cin >> t;
  while (t--) {
    int n = 0;
    cin >> n;
    int ar[50] = {0};
    int s = 0;
    int l = 0;
    for (int i = 0; i < 2 * n; i++) {
      cin >> s;
      if (!ar[s] && l < n) {
        l++;
        cout << s << " ";
        ar[s] = 1;
      }
    }
    cout << endl;
  }
  return 0;
}
