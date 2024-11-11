#include <bits/stdc++.h>
using namespace std;
vector<int> factor;
int n;
long long p = 1000000007;
void calfact(int x) {
  int i;
  for (i = 1; i * i < x; i++) {
    if (x % i) continue;
    factor.push_back(i);
    factor.push_back(x / i);
  }
  if (i * i == x) factor.push_back(i);
  sort(factor.begin(), factor.end());
}
long long inv(int x, int y) {
  if (!y) return 1;
  long long temp = inv(x, y / 2);
  temp *= temp;
  temp %= p;
  if (y & 1) temp *= x;
  return temp % p;
}
int main() {
  cin >> n;
  int a[100006];
  int max_ = 0;
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    max_ = max(max_, a[i]);
  }
  a[n] = -1;
  n++;
  long long sum = 0;
  sort(a, a + n);
  for (int i = 0; i < max_; i++) {
    calfact(i + 1);
    factor.push_back(100009);
    long long ans = 1;
    for (int j = 0; j < factor.size() - 1; j++) {
      int low = 0;
      int high = n - 1;
      while (low < high) {
        int mid = (low + high) / 2;
        if (a[mid] < factor[j]) {
          low = mid + 1;
        } else {
          high = mid;
        }
      }
      if (a[low] < factor[j]) low++;
      int lowlimit = low;
      high = n - 1;
      while (low < high) {
        int mid = (low + high + 1) / 2;
        if (a[mid] >= factor[j + 1]) {
          high = mid - 1;
        } else {
          low = mid;
        }
      }
      if (a[high] >= factor[j + 1]) high--;
      if (j != factor.size() - 2)
        ans *= inv(j + 1, high - lowlimit + 1);
      else
        ans *= inv(j + 1, high - lowlimit + 1) - inv(j, high - lowlimit + 1);
      ans %= p;
    }
    sum += ans;
    sum %= p;
    factor.clear();
  }
  cout << (sum + p) % p << endl;
}
