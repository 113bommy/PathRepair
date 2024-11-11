#include <bits/stdc++.h>
using namespace std;
long long n, k, p;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> k >> p;
  long long l = n - k;
  long long b = max(k, l) - min(k, l);
  if (l >= k) b++;
  while (p--) {
    long long x;
    cin >> x;
    if (l >= k) {
      if (b % 2 == 1) {
        if (x <= b)
          cout << ".";
        else if ((x - b) % 2 == 1)
          cout << "X";
        else
          cout << ".";
      } else {
        if (k == 0)
          cout << ".";
        else if (k == 1) {
          if (x == n)
            cout << "X";
          else
            cout << ".";
        } else {
          if (x == n || x == n - 1)
            cout << "X";
          else if (x <= b)
            cout << ".";
          else if ((x - b) % 2 == 0)
            cout << "X";
          else
            cout << ".";
        }
      }
    } else {
      if (n - x <= b - 1)
        cout << "X";
      else if (x % 2 == 0)
        cout << ".";
      else
        cout << "X";
    }
  }
}
