#include <bits/stdc++.h>
using namespace std;
struct node {
  long long val = 0;
};
bool cmp(char c1, char c2) { return c1 < c2; }
int main() {
  int testcases = 0;
  cin >> testcases;
  while (testcases--) {
    long long int n, ans = 0;
    cin >> n;
    if (n <= 15) {
      cout << 15 << endl;
      continue;
    }
    ans = (n / 6) * 15;
    if (n % 6 > 0 && n % 6 <= 2)
      ans += 5;
    else if (n % 6 > 0 && n % 6 <= 4)
      ans += 10;
    else if (n % 6 > 0 && n % 6 <= 6)
      ans += 15;
    cout << ans << endl;
  }
}
