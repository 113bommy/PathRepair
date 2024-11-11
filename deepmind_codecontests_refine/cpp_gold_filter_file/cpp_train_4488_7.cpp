#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const long long inf = LLONG_MAX;
const long long N = 1e5 + 10;
int main(void) {
  long long n, k;
  cin >> n >> k;
  map<char, int> arr, arr1;
  string str;
  cin >> str;
  for (auto v : str) {
    arr[v]++;
  }
  if (arr.size() != k) {
    cout << "0" << endl;
    return 0;
  } else {
    long long min = 100000;
    for (auto v : str) {
      if (arr[v] < min) {
        min = arr[v];
      }
    }
    for (auto v : str) {
      arr1[v] = 0;
    }
    string ans;
    for (auto v : str) {
      if (arr1[v] < min) {
        ans += v;
      }
      arr1[v]++;
    }
    cout << ans.size() << endl;
  }
  return 0;
}
