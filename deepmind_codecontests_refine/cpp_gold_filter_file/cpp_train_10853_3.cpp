#include <bits/stdc++.h>
using namespace std;
const int N = 200050, M = 1000000007;
void fastscan(int &number) {
  bool negative = false;
  register int c;
  number = 0;
  c = getchar();
  if (c == '-') {
    negative = true;
    c = getchar();
  }
  for (; (c > 47 && c < 58); c = getchar()) number = number * 10 + c - 48;
  if (negative) number *= -1;
}
bool check(string s) {
  stringstream ss;
  int n;
  ss << s;
  ss >> n;
  if (n % 8 == 0) {
    cout << "YES" << endl << n;
    return true;
  }
  return false;
}
bool check(int n) {
  if (n <= 3) return true;
  if (n % 3 == 0) return false;
  for (int i = 5; i <= sqrt(n); i += 6)
    if (n % i == 0 || n % (i + 2) == 0) return false;
  return true;
}
int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(0);
  cin.tie(NULL);
  int i, n, t, dem, gay;
  fastscan(t);
  while (t--) {
    fastscan(n);
    if (n % 2 != 0) {
      if (n == 1)
        cout << "FastestFinger";
      else
        cout << "Ashishgup";
    } else if (n == 2)
      cout << "Ashishgup";
    else {
      gay = n;
      while (n % 2 == 0) n /= 2;
      if (n > 1) {
        gay /= n;
        dem = 0;
        if (gay == 2) {
          if (!check(n))
            cout << "Ashishgup";
          else
            cout << "FastestFinger";
        } else
          cout << "Ashishgup";
      } else
        cout << "FastestFinger";
    }
    cout << endl;
  }
  return 0;
}
