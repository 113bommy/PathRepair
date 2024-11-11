#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  long long a, s = 0;
  cin >> n >> a;
  s += a;
  for (int i = 1; i < n; i++) {
    cin >> a;
    s += a + (a - 1) * i;
  }
  cout << s;
  return 0;
}
