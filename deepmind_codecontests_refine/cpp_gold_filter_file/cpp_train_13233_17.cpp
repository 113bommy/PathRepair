#include <bits/stdc++.h>
using namespace std;
long long n, a[200005], arr[200005], s = 0, c, x, cnt[1000006];
long long binarySearch(long long arr[], long long l, long long r, long long x) {
  if (r >= l) {
    int mid = (r + l) / 2;
    if (arr[mid] == x) return mid;
    if (arr[mid] > x) return binarySearch(arr, l, mid - 1, x);
    return binarySearch(arr, mid + 1, r, x);
  }
  return -1;
}
int main() {
  cin >> n;
  vector<long long> v;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    s += a[i];
    arr[i] = a[i];
    cnt[a[i]]++;
  }
  sort(arr, arr + n);
  for (int i = 0; i < n; i++) {
    c = s - a[i];
    if (c % 2 == 0) {
      c /= 2;
      x = binarySearch(arr, 0, n - 1, c);
      if (x != -1) {
        if (a[i] == arr[x] && cnt[a[i]] > 1)
          v.push_back(i + 1);
        else if (a[i] != arr[x])
          v.push_back(i + 1);
      }
    }
  }
  cout << v.size() << endl;
  for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
  cout << endl;
  return 0;
}
