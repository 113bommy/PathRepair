#include <bits/stdc++.h>
using namespace std;
int main() {
  string a, b;
  cin >> a;
  cin >> b;
  long long len_a, len_b;
  len_a = a.length();
  len_b = b.length();
  int sum_b = count(b.begin(), b.end(), '1');
  int ans = 0;
  vector<int> a1(len_a);
  a1[0] = (a[0] == '1');
  for (int i = 1; i < len_a; ++i) {
    a1[i] = a1[i - 1] + (a[i] == '1');
  }
  for (int i = len_b - 1; i < len_a; ++i) {
    int y;
    if (i == len_b - 1) {
      y = a[i];
    } else {
      y = a[i] - a[i - len_b];
    }
    if (sum_b % 2 == y % 2) {
      ans += 1;
    }
  }
  cout << ans << endl;
  return 0;
}
