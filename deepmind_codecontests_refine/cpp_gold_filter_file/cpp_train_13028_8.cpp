#include <bits/stdc++.h>
using namespace std;
using ll = long long;
bool prime(int p) {
  if (p <= 1) return false;
  if (p == 2) return true;
  int ss = ceil(sqrt(p)) + 1;
  for (int i = 2; i < ss; i++) {
    if (p % i == 0) return false;
  }
  return true;
}
int ones = 0;
int twos = 0;
int pref = 0;
void ans(int a) {
  cout << a << ' ';
  ((a == 1) ? ones : twos)--;
  pref += a;
}
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    ((a == 1) ? ones : twos)++;
  }
  int p = 0;
  for (int i = 0; i < n; i++) {
    if (ones == 0)
      ans(2);
    else if (twos == 0)
      ans(1);
    else {
      if (prime(pref + 1))
        ans(1);
      else if (prime(pref + 2))
        ans(2);
      else {
        ans(2);
      }
    }
  }
  return 0;
}
