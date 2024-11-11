#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n = 0, k = 0, s = 0, sum = 1, step = 0;
  cin >> n >> k >> s;
  step = s / k;
  if (k * (n - 1) < s || s < k) {
    cout << "NO";
    return 0;
  }
  cout << "YES" << endl;
  int tek = 1;
  for (int i = 0; i < k; ++i) {
    if (i < s % k) {
      sum += tek * (step + 1);
    } else {
      sum += tek * step;
    }
    tek = -tek;
    cout << sum << ' ';
  }
  return 0;
}
