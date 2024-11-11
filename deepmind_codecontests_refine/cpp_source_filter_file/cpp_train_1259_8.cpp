#include <bits/stdc++.h>
using namespace std;
long long int countSetBits(long long int n) {
  long long int count = 0;
  while (n) {
    n &= (n - 1);
    count++;
  }
  return count;
}
long long int power(long long int x, long long int y) {
  if (y == 0)
    return 1;
  else if (y % 2 == 0)
    return power(x, y / 2) * power(x, y / 2);
  else
    return x * power(x, y / 2) * power(x, y / 2);
}
long long int gcd(long long int a, long long int b) {
  long long int r;
  while (b) {
    r = a % b;
    a = b;
    b = r;
  }
  return a;
}
bool pr[1000007];
void sieve() {
  pr[0] = 1;
  pr[1] = 1;
  for (int i = 2; i < sqrt(1000007); i++) {
    for (int j = 2 * i; j <= 1000007; j += i) {
      pr[j] = 1;
    }
  }
}
const int MOD = 1e9 + 7;
const int SIZE = 4e6 + 10;
const int MAX = 1e9 + 1;
int main() {
  int(t);
  scanf("%d", &t);
  while (t--) {
    int(n);
    scanf("%d", &n);
    string s;
    cin >> s;
    int flag = 0;
    int i = 0;
    int j = n - 1;
    while (i < j) {
      if (s[i] != s[j]) {
        if (s[i] == 'a') {
          if (s[j] != 'd') {
            cout << "NO\n";
            flag++;
            break;
          }
        } else if (s[j] == 'a') {
          if (s[i] != 'd') {
            cout << "NO\n";
            flag++;
            break;
          }
        } else if (s[i] == 'z') {
          if (s[j] != 'w') {
            cout << "NO\n";
            flag++;
            break;
          }
        } else if (s[j] == 'z') {
          if (s[i] != 'w') {
            cout << "NO\n";
            flag++;
            break;
          }
        } else {
          if (abs(s[i] - s[j]) != 2) {
            cout << "NO\n";
            flag++;
            break;
          }
        }
      }
      i++;
      j--;
    }
    if (flag == 0) cout << "YES\n";
  }
  return 0;
}
