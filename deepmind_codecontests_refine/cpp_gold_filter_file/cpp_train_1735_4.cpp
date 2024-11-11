#include <bits/stdc++.h>
using namespace std;
long long base;
pair<int, int> factorise(long long n) {
  int i = 0;
  while (n % 2 == 0) {
    n /= 2;
    i++;
  }
  int j = 0;
  while (n % 3 == 0) {
    n /= 3;
    j--;
  }
  base = n;
  return make_pair(i, j);
}
int main() {
  int n;
  cin >> n;
  vector<pair<pair<int, int>, long long>> nums;
  for (int i = 0; i < n; ++i) {
    long long a;
    cin >> a;
    nums.push_back(make_pair(factorise(a), a));
  }
  sort(nums.begin(), nums.end());
  for (auto p : nums) cout << p.second << " ";
  cout << endl;
}
