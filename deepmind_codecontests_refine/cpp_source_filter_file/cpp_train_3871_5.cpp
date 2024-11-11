#include <bits/stdc++.h>
using namespace std;
vector<long long int> arr;
long long int n, k, val;
bool check(long long int mid) {
  long long int moves = 0;
  for (long long int i = n / 2; i < n; ++i) {
    moves += (mid - arr[i]);
    if (moves > k) return false;
  }
  return true;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> k;
  for (long long int i = 0; i < n; ++i) {
    cin >> val;
    arr.push_back(val);
  }
  sort(arr.begin(), arr.end());
  long long int small = 1;
  long long int big = pow(10, 9);
  while (small < big) {
    long long int mid = (small + big + 1) / 2;
    if (check(mid)) {
      small = mid;
    } else
      big = mid - 1;
  }
  cout << small << endl;
}
