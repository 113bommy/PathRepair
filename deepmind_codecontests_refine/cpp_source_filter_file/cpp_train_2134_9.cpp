#include <bits/stdc++.h>
using namespace std;
void setup() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cout.precision(15);
}
bool check(int a, int b, int A, int B) {
  if (a <= A and b <= B)
    return true;
  else
    return false;
}
int main() {
  int A, B, a, b, c, d;
  cin >> A >> B >> a >> b >> c >> d;
  string ans = "NO";
  if (check(a, b, A, B)) {
    if (check(c, d, A - a, B) || check(d, c, A - a, B) ||
        check(c, d, A, B - b) || check(d, c, A, B - b))
      ans = "YES";
  } else if (check(b, a, A, B)) {
    if (check(c, d, A - b, B) || check(d, c, A - b, B) ||
        check(c, d, A, B - a) || check(d, c, A, B - a))
      ans = "YES";
  }
  cout << ans << '\n';
  return 0;
}
