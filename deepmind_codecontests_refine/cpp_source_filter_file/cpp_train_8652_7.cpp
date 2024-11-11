#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
long long power(long long a, long long b, long long modi) {
  long long res = 1;
  while (b) {
    if (b % 2) {
      res = (res * a) % modi;
    }
    b /= 2;
    a = (a * a) % modi;
  }
  return res;
}
int fre[200001];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  while (t--) {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      fre[x]++;
    }
    int low = 1;
    int high = n;
    int mid;
    int ans = 0;
    while (low <= high) {
      mid = (low + high) / 2;
      int sum = 0;
      for (int i = 1; i < 200001; i++) {
        sum += fre[i] / mid;
      }
      if (sum >= mid) {
        low = mid + 1;
        ans = mid;
      } else
        high = mid - 1;
    }
    vector<int> solution;
    bool flag = false;
    for (int i = 1; i < 200001; i++) {
      int h = fre[i] / ans;
      for (int j = 0; j < h; j++) {
        solution.push_back(i);
        if (solution.size() >= k) {
          flag = true;
          break;
        }
      }
      if (flag) break;
    }
    for (int i = 0; i < k; i++) cout << solution[i] << " ";
  }
  return 0;
}
