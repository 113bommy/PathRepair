#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(0);
  long long int n;
  cin >> n;
  if (n == 1 || n == 7 || n == 9 || n == 11 || n == 13 || n == 14 || n == 15 ||
      n == 16 || n == 17 || n == 18 || n == 19 || (n >= 21 && n <= 29) ||
      n == 31 || n == 37 || n == 39 || n == 41 || n == 47 || n == 49 ||
      n == 51 || n == 57 || n == 59 || n == 61 || n == 67 || n == 69 ||
      (n >= 70 && n <= 79) || n == 81 || n == 87 || n == 89 ||
      (n >= 90 && n <= 99) || n == 10)
    cout << "NO";
  else
    cout << "YES";
  return 0;
}
