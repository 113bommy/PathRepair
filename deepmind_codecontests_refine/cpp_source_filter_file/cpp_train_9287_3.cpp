#include <bits/stdc++.h>
using namespace std;
int findFirst(const std::vector<int> &array, int key, int low, int high) {
  int ans = -1;
  while (low <= high) {
    int mid = low + (high - low) / 2;
    if (key == array[mid]) {
      ans = mid;
      high = mid - 1;
    } else if (key > array[mid])
      low = mid + 1;
    else
      high = mid - 1;
  }
  return ans;
}
int findLast(const std::vector<int> &array, int key, int low, int high) {
  int ans = -1;
  while (low <= high) {
    int mid = low + (high - low) / 2;
    if (key == array[mid]) {
      ans = mid;
      low = mid + 1;
    } else if (key > array[mid])
      low = mid + 1;
    else
      high = mid - 1;
  }
  return ans;
}
int d, x, y;
void extendedEuclid(int a, int b) {
  if (b == 0) {
    d = 1;
    x = 1;
    y = 0;
  } else {
    extendedEuclid(b, a % b);
    int temp = x;
    x = y;
    y = temp - (a / b) * y;
  }
}
int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int t;
  cin >> t;
  for (int tc = 0; tc < t; tc++) {
    long long int n, d;
    cin >> n >> d;
    if (d <= n) {
      cout << "YES" << endl;
      continue;
    }
    int low = 1, high = n, ans = -1;
    while (low <= high) {
      int mid = (low + high) / 2;
      int temp = mid + ceil((long double)d / (long double)(mid + 1));
      if (temp <= n) {
        ans = mid;
        break;
      } else {
        low = mid + 1;
      }
    }
    if (ans == -1)
      cout << "NO" << endl;
    else
      cout << "YES" << endl;
  }
  return 0;
}
