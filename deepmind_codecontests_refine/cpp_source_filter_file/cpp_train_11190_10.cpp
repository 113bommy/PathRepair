#include <bits/stdc++.h>
using namespace std;
vector<int> digits;
int w, m;
bool solve() {
  digits.push_back(0);
  for (int i = 0; i < digits.size(); i++) {
    if (digits[i] == 1 || digits[0] == 0) {
      continue;
    } else if (digits[i] == w - 1 || digits[i] == w) {
      digits[i + 1]++;
    } else
      return false;
  }
  return true;
}
int main() {
  std::ios::sync_with_stdio(false);
  cin >> w >> m;
  if (w == 2) {
    cout << "YES";
    return 0;
  }
  while (1) {
    digits.push_back(m % w);
    m = m / w;
    if (m < w) {
      digits.push_back(m);
      break;
    }
  }
  if (solve())
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
