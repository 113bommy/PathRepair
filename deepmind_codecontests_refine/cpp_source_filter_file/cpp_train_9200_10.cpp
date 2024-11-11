#include <bits/stdc++.h>
using namespace std;
const long long MX = 1e5;
long long n, m, k, a[MX], l[MX], r[MX], d[MX], x, y, arr[MX], ar[MX];
int main() {
  cin >> n >> m >> k;
  for (int i = 1; i < n + 1; i++) {
    cin >> a[i];
  }
  for (int i = 1; i < m + 1; i++) {
    cin >> l[i] >> r[i] >> d[i];
  }
  for (int i = 1; i < k + 1; i++) {
    cin >> x >> y;
    arr[x]++;
    arr[y + 1]--;
  }
  for (int i = 1; i < m + 1; i++) {
    arr[i] = arr[i] + arr[i - 1];
  }
  for (int i = 1; i < m + 1; i++) {
    ar[l[i]] += d[i] * arr[i];
    ar[r[i] + 1] -= d[i] * arr[i];
  }
  for (int i = 1; i < n + 1; i++) {
    ar[i] += ar[i - 1];
    long long finish = a[i] + ar[i];
    cout << finish << " ";
  }
}
