#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  long long a, b;
  for (int i = 0; i < t; i++) {
    cin >> a >> b;
    if (a == b) {
      cout << 0 << endl;
      continue;
    }
    long long diff = abs(a - b);
    long long answer = 0;
    long long div = diff / 5;
    answer += div;
    if (diff % 5 == 0) {
      cout << answer << endl;
      continue;
    }
    diff -= div * 5;
    div = diff / 2;
    answer += div;
    if (diff % 2 == 0) {
      cout << answer << endl;
      continue;
    }
    diff -= div * 2;
    div = diff / 1;
    answer += div;
    if (diff % 1 == 0) {
      cout << answer << endl;
      continue;
    }
  }
  return 0;
}
