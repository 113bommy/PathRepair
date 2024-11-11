#include <bits/stdc++.h>
using namespace std;
const long long int mod = 1e9 + 7;
const double PI = acos(-1.0);
const int MAXN = 1e6 + 5;
set<long long int> nums;
vector<long long int> arr;
void init(int len, int nz, long long int num) {
  nums.insert(num);
  if (len) {
    if (nz) {
      for (int i = 1; i <= 9; i++) {
        init(len - 1, nz - 1, num * 10 + i);
      }
    }
    init(len - 1, nz, num * 10);
  }
}
int bin(long long int num) {
  int ind = 0;
  int lo = 0, hi = ((int)arr.size()) - 1;
  while (lo <= hi) {
    int mid = (lo + hi) / 2;
    if (arr[mid] <= num)
      ind = mid, lo = mid + 1;
    else
      hi = mid - 1;
  }
  return ind;
}
void cp() {
  long long int l, r;
  cin >> l >> r;
  cout << bin(r) - bin(l - 1) << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int t;
  init(19, 3, 0);
  arr = vector<long long int>(nums.begin(), nums.end());
  t = 1;
  cin >> t;
  while (t--) {
    cp();
  }
  return 0;
}
