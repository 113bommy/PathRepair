#include <bits/stdc++.h>
using namespace std;
int binary(long long int s[], int t, int m) {
  int l = 0, h = m - 1;
  while (l <= h) {
    int mid = (l + h) / 2;
    if (s[mid] == t)
      return mid;
    else if (l == h)
      return l;
    else if (t > s[mid])
      l = mid + 1;
    else if (t < s[mid])
      h = mid - 1;
  }
}
int main() {
  int n;
  cin >> n;
  long long int sum[n + 1];
  sum[0] = 0;
  for (int i = 1; i <= n; i++) {
    int temp;
    cin >> temp;
    sum[i] = sum[i - 1] + temp;
  }
  int m;
  cin >> m;
  for (int i = 0; i < m; i++) {
    int t1;
    cin >> t1;
    long long int y = binary(sum, t1, n + 1);
    cout << y << endl;
  }
}
