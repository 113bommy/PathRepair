#include <bits/stdc++.h>
using namespace std;
long long int isPrime(long long int n) {
  if (n <= 1) return 0;
  if (n <= 3) return 1;
  if (n % 2 == 0 || n % 3 == 0) return 0;
  for (long long int i = 5; i * i <= n; i = i + 6)
    if (n % i == 0 || n % (i + 2) == 0) return 0;
  return 1;
}
int32_t main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  string str;
  long long int flag = 0, h = 0, i = 0, e = 0, d = 0;
  cin >> str;
  for (long long int i = 0; i < str.length(); i++) {
    if ((str[i] == 'h') && (flag == 0)) {
      flag = 1;
    } else if ((str[i] == 'e') && (flag == 1)) {
      flag = 2;
    } else if ((str[i] == 'i') && (flag == 2)) {
      flag = 3;
    } else if ((str[i] == 'd') && (flag == 3))
      flag = 4;
    else if ((str[i] == 'i') && ((flag == 4))) {
      flag = 5;
      break;
    }
  }
  if (flag != 5)
    cout << "NO";
  else
    cout << "YES";
  cout.flush();
  return 0;
}
