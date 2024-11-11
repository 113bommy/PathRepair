#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int t;
  t = 1;
  for (int tc = 0; tc < t; tc++) {
    int n;
    long long int l, x, y;
    cin >> n >> l >> x >> y;
    vector<long long int> arr(n + 1), pre(n + 1, 0);
    for (int i1 = 1; i1 <= n; i1++) cin >> arr[i1];
    pre[1] = arr[1];
    for (int i = 2; i <= n; i++) pre[i] = pre[i - 1] + arr[i];
    bool g1 = 0, g2 = 0;
    long long int d = x;
    for (int i = 1; i <= n; i++) {
      long long int temp = d + arr[i];
      if (binary_search(arr.begin() + i, arr.end(), temp)) {
        g1 = 1;
        break;
      }
    }
    d = y;
    for (int i = 1; i <= n; i++) {
      long long int temp = d + arr[i];
      if (binary_search(arr.begin() + i, arr.end(), temp)) {
        g2 = 1;
        break;
      }
    }
    vector<long long int> v;
    long long int a = -1, a1 = -1;
    if (!g1 && g2)
      v.push_back(x);
    else if (g1 && !g2)
      v.push_back(y);
    else if (!g1 && !g2) {
      bool flag = 0;
      for (int i = 1; i <= n; i++) {
        if (arr[i] - x >= 0) {
          if (arr[i] - x + y >= 0 && arr[i] - x + y <= l &&
              binary_search(arr.begin(), arr.end(), arr[i] - x + y)) {
            flag = 1;
            v.push_back(arr[i] - x);
            break;
          }
        }
      }
      if (!flag) {
        for (int i = 1; i <= n; i++) {
          if (arr[i] + x >= 0) {
            if (arr[i] + x + y >= 0 && arr[i] + x + y <= l &&
                binary_search(arr.begin(), arr.end(), arr[i] + x + y)) {
              flag = 1;
              v.push_back(arr[i] + x);
              break;
            }
          }
        }
      }
      if (!flag) {
        for (int i = 1; i <= n; i++) {
          if (arr[i] - y >= 0) {
            if (arr[i] + x - y >= 0 && arr[i] + x - y <= l &&
                binary_search(arr.begin(), arr.end(), arr[i] + x - y)) {
              flag = 1;
              v.push_back(arr[i] - y);
              break;
            }
          }
        }
      }
      if (!flag) {
        for (int i = 1; i <= n; i++) {
          if (arr[i] + y >= 0) {
            if (arr[i] - x + y >= 0 && arr[i] - x + y <= l &&
                binary_search(arr.begin(), arr.end(), arr[i] - x + y)) {
              flag = 1;
              v.push_back(arr[i] + y);
              break;
            }
          }
        }
      }
      if (!flag) {
        v.push_back(x);
        v.push_back(y);
      }
    }
    cout << v.size() << "\n";
    for (int i = 0; i < (int)v.size(); i++) cout << v[i] << " ";
    cout << "\n";
    ;
  }
  return 0;
}
