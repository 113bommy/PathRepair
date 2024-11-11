#include <bits/stdc++.h>
using namespace std;
const int INF = 987654321;
const int MOD = 1000000007;
int order(const vector<int>& russian, const vector<int>& korean) {
  int n = russian.size(), wins = 0;
  int ret = 0;
  multiset<int> ratings(korean.begin(), korean.end());
  for (int rusI = 0; rusI < n; ++rusI) {
    if (*ratings.rbegin() < russian[rusI]) {
      ratings.erase(ratings.begin());
      ++ret;
    } else {
      ratings.erase(ratings.lower_bound(russian[rusI]));
    }
  }
  return ret;
}
int order2(const vector<int>& russian, const vector<int>& korean) {
  int n = russian.size(), wins = 0;
  multiset<int> ratings(korean.begin(), korean.end());
  for (int rusI = 0; rusI < n; ++rusI) {
    if (*ratings.rbegin() <= russian[rusI])
      ratings.erase(ratings.begin());
    else {
      ratings.erase(ratings.upper_bound(russian[rusI]));
      ++wins;
    }
  }
  return wins;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  string str1, str2;
  cin >> str1 >> str2;
  vector<int> arr1(n), arr2(n);
  for (int i = 0; i < (n); ++i) arr1[i] = str1[i] - '0';
  for (int i = 0; i < (n); ++i) arr2[i] = str2[i] - '0';
  sort(arr1.begin(), arr1.end());
  sort(arr2.begin(), arr2.end());
  int sol1 = order(arr1, arr2);
  int sol2 = order2(arr1, arr2);
  cout << sol1 << '\n' << sol2;
  return 0;
}
