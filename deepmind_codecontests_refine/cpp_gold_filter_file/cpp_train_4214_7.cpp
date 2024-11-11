#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a, b, c, d;
  int arr[4];
  double mean, med, rang;
  scanf("%d", &n);
  if (n == 0) {
    cout << "YES" << endl;
    cout << "1\n1\n3\n3\n";
  }
  if (n == 4) {
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    sort(arr, arr + n);
    mean = (double)(arr[0] + arr[1] + arr[2] + arr[3]) / 4;
    med = (double)(arr[1] + arr[2]) / 2;
    rang = arr[3] - arr[0];
    if (mean == med && rang == med)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  if (n == 3) {
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    for (int k = 1; k <= 1000000; k++) {
      int temp[4];
      temp[0] = arr[0];
      temp[1] = arr[1];
      temp[2] = arr[2];
      temp[3] = k;
      sort(temp, temp + 4);
      mean = (double)(temp[0] + temp[1] + temp[2] + temp[3]) / 4;
      med = (double)(temp[1] + temp[2]) / 2;
      rang = temp[3] - temp[0];
      if (mean == med && rang == med) {
        cout << "YES" << endl;
        cout << k << endl;
        return 0;
      }
    }
    cout << "NO" << endl;
  }
  if (n == 1) {
    scanf("%d", &a);
    cout << "YES" << endl;
    cout << a << endl << 3 * a << endl << 3 * a << endl;
  }
  if (n == 2) {
    cin >> a >> b;
    int x = min(a, b), y = max(a, b);
    if (y > 3 * x)
      cout << "NO" << endl;
    else {
      cout << "YES" << endl;
      cout << 3 * x << endl;
      cout << 4 * x - y << endl;
    }
  }
  return 0;
}
