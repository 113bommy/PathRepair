#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string s1, s2;
  cin >> s1 >> s2;
  int n = s2.length();
  int c = 0;
  int g = -1;
  int j = 0;
  int f = 0;
  int i;
  for (i = 0; i < n;) {
    if (s1[j] != s2[i]) {
      if (c > 0) {
        f = 1;
        break;
      }
      g = j;
      c++;
      i--;
    }
    if (i == n - 1 && j == n - 1) {
      g = j + 1;
    }
    j++;
    i++;
    if (j > n) {
      break;
    }
  }
  if (i < n || f == 1) {
    cout << "0\n";
  } else {
    int p;
    if (g != 0) {
      for (p = g; p > 0; p--) {
        if (s1[p] != s1[p - 1]) {
          break;
        }
      }
      cout << g - p + 1 << "\n";
      for (int i = p; i <= g; i++) {
        cout << i + 1 << " ";
      }
      cout << "\n";
    } else {
      cout << "1\n1\n";
    }
  }
  return 0;
}
