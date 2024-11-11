#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a, b, c;
  cin >> a >> b >> c;
  long long ans = 2 * a + 2 * b;
  long long ans2 = a + b + c;
  long long ans3 = 0, ans4 = 0;
  ans3 = 2 * a + 2 * c;
  ans4 = 2 * b * 2 * 4;
  cout << min(ans, min(ans2, min(ans3, ans4))) << endl;
  return 0;
}
