#include <bits/stdc++.h>
using namespace std;
const long long mx = 2e5 + 5;
long long n, arr[mx], s[mx], maxx, num, j;
int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> s[i];
    arr[s[i]]++;
    if (maxx < arr[s[i]]) {
      maxx = arr[s[i]];
      num = s[i];
    }
  }
  for (int i = 0; i < n; i++) {
    if (s[i] == num) {
      j = i;
      break;
    }
  }
  cout << n - maxx << endl;
  for (int i = j; i >= 0; i--) {
    if (s[i] == num) continue;
    if (s[i] < num) {
      cout << 1 << " ";
    } else {
      cout << 2 << " ";
    }
    cout << i + 1 << " " << i + 2 << endl;
  }
  for (int i = j; i < n; i++) {
    if (s[i] == num) continue;
    if (s[i] < num) {
      cout << 1 << " ";
    } else {
      cout << 2 << " ";
    }
    cout << i + 1 << " " << i << " " << endl;
  }
  return 0;
}
