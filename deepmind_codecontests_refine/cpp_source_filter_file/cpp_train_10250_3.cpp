#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, a[26] = {0};
  long long money = 0;
  char ch;
  cin >> n >> k;
  while (n--) {
    cin >> ch;
    a[ch - 'A']++;
  }
  sort(a, a + 26);
  n = 25;
  while (k > 0) {
    if (k >= a[n])
      money += a[n] * a[n];
    else
      money += k * k;
    k -= a[n];
    n--;
  }
  cout << money;
}
