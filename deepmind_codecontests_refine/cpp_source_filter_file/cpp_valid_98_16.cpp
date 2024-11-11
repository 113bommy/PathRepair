#include <bits/stdc++.h>
using namespace std;
const long long N = 1e9 + 1;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    char arr[n + 10];
    for (int i = 1; i <= n; i++) {
      cin >> arr[i];
    }
    int l = -1, r = -1;
    for (int i = 1; i < n; i += 1) {
      if (arr[i] == 'a' && arr[i + i] == 'b') {
        l = i;
        r = i + 1;
        break;
      }
      if (arr[i] == 'b' && arr[i + 1] == 'a') {
        l = i;
        r = i + 1;
        break;
      }
    }
    cout << l << " " << r << "\n";
  }
  return 0;
}
