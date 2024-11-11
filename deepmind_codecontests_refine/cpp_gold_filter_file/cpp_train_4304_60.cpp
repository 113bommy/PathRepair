#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int i;
  int answer = 1;
  for (i = 2; i <= n; i++) {
    answer += (6 * (2 * i - 2));
  }
  cout << answer << endl;
  return 0;
}
