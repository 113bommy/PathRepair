#include <bits/stdc++.h>
using namespace std;
long long int gcd(long long int a, long long int b) {
  if (b != 0)
    return gcd(b, a % b);
  else
    return a;
}
long long int power(long long int a, long long int b) {
  if (b == 0) return 1;
  if (b == 1) return a;
  if (b % 2 == 0) {
    long long int t = power(a, b / 2);
    return t * t;
  } else {
    long long int t = power(a, b / 2);
    return a * t * t;
  }
}
long long int powin(long long int a, long long int b) {
  if (b == 0)
    return 1;
  else if (b == 1)
    return a;
  else if (b % 2 == 0) {
    long long int t = powin(a, b / 2);
    return (t * t) % 1000000007;
  } else {
    long long int t = powin(a, b / 2);
    return (((t * t) % 1000000007) * a) % 1000000007;
  }
}
long long int l[1000000][2];
int main() {
  long long int n;
  cin >> n;
  memset(l, 0, sizeof l);
  long long int c = 0;
  for (int j = 0; j < n; j++) {
    string s;
    cin >> s;
    int p = 0;
    int q = 0;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '(') {
        p++;
      } else
        q++;
    }
    if (p == q) {
      int x = 0;
      int y = 0;
      for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
          x++;
        } else {
          y++;
        }
        if (y > x) {
          c--;
          break;
        }
      }
      c++;
    } else if (p > q) {
      int x = 0;
      int y = 0;
      for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
          x++;
        } else {
          y++;
        }
        if (y > x) {
          l[p - q][0]--;
          break;
        }
      }
      l[p - q][0]++;
    } else {
      int x = 0;
      int y = 0;
      for (int i = s.size() - 1; i >= 0; i--) {
        if (s[i] == '(') {
          x++;
        } else {
          y++;
        }
        if (y < x) {
          l[q - p][1]--;
          break;
        }
      }
      l[q - p][1]++;
    }
  }
  long long int ans = 0;
  ans += c * c;
  for (int i = 0; i < 1000000; i++) {
    ans += l[i][0] * l[i][1];
  }
  cout << ans << endl;
  return 0;
}
