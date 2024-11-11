#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int inp[100007] = {};
  unordered_map<int, int> m;
  for (int i = 0; i < n; i++) {
    cin >> inp[i];
    m[inp[i]] = i + 1;
  }
  int sum1 = 0, sum2 = 0;
  int ma;
  cin >> ma;
  int inpm[100007] = {};
  for (int i = 0; i < ma; i++) {
    cin >> inpm[i];
    sum1 += m[inpm[i]];
    sum2 += n + 1 - m[inpm[i]];
  }
  cout << sum1 << " " << sum2;
  return 0;
}
