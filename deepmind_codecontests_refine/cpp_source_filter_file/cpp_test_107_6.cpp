#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int arr[N];
int main(void) {
  int T;
  cin >> T;
  while (T--) {
    int n, a, b;
    cin >> n >> a >> b;
    bool flag = true;
    for (int i = 1; i <= n; i++) arr[i] = i;
    int maxv = (n - 2) / 2 + (n & 1);
    if (a > maxv || b > maxv)
      flag = false;
    else if (abs(a - b) > 1)
      flag = false;
    else if ((n & 1) && a == maxv && b == maxv)
      flag = false;
    else if (a == 0 && b == 0) {
      for (int i = 1; i <= n; i++) arr[i] = i;
    } else {
      if (a == b) {
        int l = 1, r = n;
        for (int i = 1; i <= b * 2 + 1; i += 2) arr[i] = r--;
        for (int i = 2; i <= a * 2; i += 2) arr[i] = l++;
        for (int i = 2 * b + 2; i <= n; i++) arr[i] = l++;
      } else if (a == b + 1) {
        int l = 1, r = n;
        for (int i = 1; i <= a * 2; i += 2) arr[i] = l++;
        for (int i = 2; i <= a * 2; i += 2) arr[i] = r--;
        for (int i = 2 * a + 1; i <= n; i++) arr[i] = r--;
      } else {
        int l = 1, r = n;
        for (int i = 1; i <= b * 2; i += 2) arr[i] = r--;
        for (int i = 2; i <= b * 2; i += 2) arr[i] = l++;
        for (int i = 2 * b + 1; i <= n; i++) arr[i] = l++;
      }
    }
    if (flag) {
      for (int i = 1; i <= n; i++) cout << arr[i] << " ";
      cout << endl;
    } else
      cout << "-1" << endl;
  }
  return 0;
}
