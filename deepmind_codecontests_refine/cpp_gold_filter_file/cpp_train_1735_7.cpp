#include <bits/stdc++.h>
using namespace std;
inline void init_code() {}
const long long int N = 105;
long long int arr[N];
long long int n;
vector<long long int> ans_arr;
bool bsearch(long long int val) {
  long long int l = -1, r = n, mid;
  while (r - l > 1) {
    mid = (l + r) / 2;
    if (arr[mid] < val)
      l = mid;
    else
      r = mid;
  }
  if (arr[r] == val) return true;
  return false;
}
void dfs_one(long long int number) {
  long long int num = -1;
  long long int val = number * 3;
  if (bsearch(val)) {
    num = val;
  }
  if (!(number & 1)) {
    val = number / 2;
    if (bsearch(val)) {
      num = val;
    }
  }
  if (num != -1) {
    dfs_one(num);
  }
  ans_arr.push_back(number);
}
void dfs_two(long long int number) {
  long long int num = -1;
  long long int val = number << 1;
  if (bsearch(val)) {
    num = val;
  }
  if (number % 3 == 0) {
    val = number / 3;
    if (bsearch(val)) {
      num = val;
    }
  }
  if (num != -1) {
    ans_arr.push_back(num);
    dfs_two(num);
  }
}
void solve() {
  cin >> n;
  for (long long int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  sort(arr, arr + n);
  dfs_one(arr[0]);
  dfs_two(arr[0]);
  for (long long int i : ans_arr) {
    cout << i << " ";
  }
  cout << '\n';
}
int32_t main() {
  init_code();
  solve();
  return 0;
}
