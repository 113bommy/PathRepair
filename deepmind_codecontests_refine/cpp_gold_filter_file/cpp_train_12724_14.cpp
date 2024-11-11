#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100 * 1000 + 100;
int arr[MAXN];
int n;
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> arr[i];
  sort(arr, arr + n);
  int s1 = 1;
  int s2 = 1;
  for (int i = 0; i < n - 1; i++) {
    if (arr[i] == arr[n - 1]) {
      cout << "NO" << endl;
      return 0;
    }
    if (arr[i] == arr[i + 1])
      s1++;
    else {
      if (arr[i + 1] == arr[n - 1] && n - i - s1 - 1 != 0) {
        cout << "NO" << endl;
        return 0;
      }
      if (arr[i] != arr[i + 1] - 1) {
        cout << "NO" << endl;
        return 0;
      }
      for (int j = i + 1; j < n - 1; j++) {
        if (arr[j] == arr[j + 1])
          s2++;
        else
          break;
      }
      if (s1 >= s2 && arr[i + 1] != arr[n - 1]) {
        cout << "NO" << endl;
        return 0;
      }
      i = i + s1;
      s1 = 1, s2 = 1;
    }
  }
  cout << "YES" << endl;
  return 0;
}
