#include <bits/stdc++.h>
using namespace std;
int main() {
  std::ios::sync_with_stdio(false);
  int k;
  cin >> k;
  k *= 2;
  int digits[10] = {};
  string tmp;
  for (int i = 1; i <= 4; i++) {
    cin >> tmp;
    for (int j = 0; j < 4; j++)
      if (isdigit(tmp[j])) digits[tmp[j]]++;
  }
  bool flag = true;
  for (int i = 0; i < 10; i++)
    if (digits[i] > k) {
      flag = false;
      break;
    }
  if (flag)
    cout << "YES";
  else
    cout << "NO";
}
