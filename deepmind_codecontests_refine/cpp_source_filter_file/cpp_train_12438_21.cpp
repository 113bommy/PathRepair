#include <bits/stdc++.h>
using namespace std;
int n, a[200005];
bool ok(int mid) {
  int temp = a[0] + mid, k = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] > temp) {
      if (k < 2) {
        temp = a[i] + mid;
        k++;
      } else
        return 0;
    }
  }
  return 1;
}
int main() {
  int st = 0, ed, mid, temp, k = 0;
  double answer;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a + n);
  ed = a[n - 1];
  while (st < ed) {
    mid = (st + ed) / 2;
    if (ok(mid))
      ed = mid;
    else
      st = mid + 1;
  }
  temp = a[0] + st;
  answer = st / 2.0;
  cout << fixed << setprecision(6) << answer << endl;
  cout << fixed << setprecision(6) << a[0] + answer << " ";
  for (int i = 0; i < n; i++) {
    if (a[i] > temp) {
      temp = a[i] + st;
      k++;
      cout << fixed << setprecision(6) << a[i] + answer << " ";
    }
  }
  while (k < 2) {
    k++;
    cout << fixed << setprecision(6) << a[n - 1] / 1.0;
  }
  return 0;
}
