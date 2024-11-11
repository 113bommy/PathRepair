#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
using namespace std;
int inf = 1e9 + 5;
const double PI = 3.1415926535897932384626433832795;
int IND;
int n;
bool cmp(int a, int b) {
  if (a > IND && b > IND) return a < b;
  if (a < IND && b < IND)
    return a < b;
  else
    return b < a;
}
int main() {
  int m;
  cin >> n >> m;
  vector<vector<int>> arr(n);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    arr[a - 1].push_back(b - 1);
  }
  int l = 0;
  for (auto& i : arr) {
    IND = l;
    sort(i.rbegin(), i.rend(), cmp);
    l++;
  }
  for (int i = 0; i < n; ++i) {
    int ind = i;
    int k = 0;
    vector<int> lastInd(n);
    map<int, int> bag;
    IND = i;
    int t = 0;
    while (k < m) {
      ind %= n;
      if (lastInd[ind] < arr[ind].size()) {
        bag[arr[ind][lastInd[ind]]]++;
        lastInd[ind]++;
      }
      k += bag[ind];
      bag[ind] = 0;
      t++;
      ind++;
    }
    cout << max(t - 1, 0) << ' ';
  }
  return 0;
}
