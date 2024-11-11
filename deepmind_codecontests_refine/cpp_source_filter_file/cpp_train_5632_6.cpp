#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  int arr[m];
  for (int i = 0; i < m; i++) cin >> arr[i];
  ;
  map<int, int> ma;
  vector<int> v;
  for (int i = 0; i < m; i++) {
    ma[arr[i]]++;
  }
  for (int i = 0; i < 101; i++) {
    if (ma[i] > 0) v.push_back(ma[i]);
  }
  int num = 0, res;
  for (int i = 1; i < 101; i++) {
    num = 0;
    for (int k = 0; k < v.size(); k++) {
      num += v[k] / i;
    }
    if (num >= n) {
      if (i > res) res = i;
    }
  }
  if (res >= 0)
    cout << res;
  else
    cout << 0;
}
