#include <bits/stdc++.h>
using namespace std;
long long int gcd(long long int a, long long int b) {
  if (b < a) {
    long long int temp = a;
    a = b;
    b = temp;
  }
  if (a == 0) {
    return b;
  }
  return gcd(b % a, a);
}
long long int lcm(long long int a, long long int b) {
  return (a * b / gcd(a, b));
}
long long int fact(long long int x) {
  long long int ans = 1;
  if (x == 0) {
    return 1;
  }
  while (x > 0) {
    ans = (ans * x);
    x--;
  }
  return ans;
}
long long int power(long long int a, long long int b) {
  long long int ans = 1;
  while (b > 0) {
    if (b % 2 == 1) {
      ans *= a;
      ans = ans;
    }
    b /= 2;
    a *= a;
    a = a;
  }
  return ans;
}
vector<long long int> getbinary(int x) {
  vector<long long int> bin(10, 0);
  long long int iter = 0;
  while (x > 0) {
    if (x % 2 == 1) {
      bin[iter] = 1;
    } else {
      bin[iter] = 0;
    }
    iter++;
    x /= 2;
  }
  return bin;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int n, k, i, j;
  cin >> n >> k;
  int a[n + 1][2 * k + 1], b[n + 1][2 * k + 1];
  char c, s[n + 1][2 * k + 1];
  for (i = 0; i < 2 * k + 1; i++) a[0][i] = 0;
  a[0][k] = 1;
  for (i = 1; i < n + 1; i++) {
    cin >> c;
    a[i][0] = a[i][2 * k] = 0;
    for (j = (i == n ? 0 : 1);
         (i < n && j <= 2 * k) || (i == n && j <= 2 * k + 1); j++) {
      if (c == 'W') {
        if (j == 0) continue;
        a[i][j] = a[i - 1][j - 1];
        b[i][j] = j - 1;
        s[i][j] = c;
      } else if (c == 'L') {
        if (j == 2 * k) continue;
        a[i][j] = a[i - 1][j + 1];
        b[i][j] = j + 1;
        s[i][j] = c;
      } else if (c == 'D') {
        a[i][j] = a[i - 1][j];
        b[i][j] = j;
        s[i][j] = c;
      } else {
        if (a[i - 1][j]) {
          a[i][j] = a[i - 1][j];
          b[i][j] = j;
          s[i][j] = 'D';
          continue;
        }
        if (j != 0 && a[i - 1][j - 1]) {
          a[i][j] = a[i - 1][j - 1];
          b[i][j] = j - 1;
          s[i][j] = 'W';
          continue;
        }
        if (j != 2 * k) {
          a[i][j] = a[i - 1][j + 1];
          b[i][j] = j + 1;
          s[i][j] = 'L';
          continue;
        }
      }
    }
  }
  if (a[n][0] || a[n][2 * k]) {
    vector<char> ans;
    if (a[n][0]) {
      j = b[n][0];
      ans.push_back(s[n][0]);
    } else {
      j = b[n][2 * k];
      ans.push_back(s[n][2 * k]);
    }
    for (i = n - 1; i > 0; i--) {
      ans.push_back(s[i][j]);
      j = b[i][j];
    }
    long long int w = 0;
    for (i = ans.size() - 1; i > 0; i--) {
      if (ans[i] == 'W')
        w++;
      else if (ans[i] == 'L')
        w--;
      if (w >= k || w <= -k) {
        cout << "NO" << endl;
        return 0;
      }
    }
    for (i = ans.size() - 1; i >= 0; i--) {
      cout << ans[i];
    }
  } else
    cout << "NO" << endl;
}
