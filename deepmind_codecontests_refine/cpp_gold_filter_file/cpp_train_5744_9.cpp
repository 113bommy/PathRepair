#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int s;
  cin >> s;
  for (int i = s; i < s + 7; ++i) {
    int t = i;
    int sum = 0;
    while (t != 0) {
      sum += t % 10;
      t /= 10;
    }
    if (sum % 4 == 0) {
      cout << i << endl;
      break;
    }
  }
  return 0;
}
