#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int n, q;
  cin >> n >> q;
  bool even = true;
  if (n % 2) even = false;
  while (q--) {
    if (even) {
      long long int x, y;
      cin >> x >> y;
      if ((x + y) % 2) {
        long long int num = (n * n) / 2;
        num += (x - 1) * (n / 2);
        if (y % 2) {
          num += y / 2;
          cout << num + 1 << "\n";
        } else {
          num += y / 2;
          cout << num << "\n";
        }
      } else {
        long long int num = (x - 1) * (n / 2);
        if (y % 2) {
          num += y / 2;
          cout << num + 1 << "\n";
        } else {
          num += y / 2;
          cout << num << "\n";
        }
      }
    } else {
      long long int x, y;
      cin >> x >> y;
      if ((x + y) % 2) {
        long long int num = ((n * n) / 2) + 1;
        if (x % 2 && x > 2) {
          num += (x / 2) * n;
          num += y / 2;
          cout << num << "\n";
        } else if (x % 2) {
          cout << y / 2 << "\n";
        } else if ((x % 2) == 0 && x > 2) {
          num += ((x / 2) - 1) * n;
          num += n / 2;
          cout << num + (y + 1) / 2 << "\n";
        } else if ((x % 2) == 0) {
          num += n / 2;
          cout << num + (y + 1) / 2 << "\n";
        }
      } else {
        long long int num = 0;
        if (x % 2 && x > 2) {
          num += (x / 2) * n;
          num += (y + 1) / 2;
          cout << num << "\n";
        } else if (x % 2) {
          cout << (y + 1) / 2 << "\n";
        } else if ((x % 2) == 0 && x > 2) {
          num += ((x / 2) - 1) * n;
          num += (n / 2) + 1;
          cout << num + y / 2 << "\n";
        } else if ((x % 2) == 0) {
          num += (n / 2) + 1;
          cout << num + y / 2 << "\n";
        }
      }
    }
  }
  return 0;
}
