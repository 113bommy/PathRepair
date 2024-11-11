#include <bits/stdc++.h>
using namespace std;
int ri() {
  bool minus = false;
  int result = 0;
  char ch;
  ch = getchar();
  while (true) {
    if (ch == '-') break;
    if (ch >= '0' && ch <= '9') break;
    ch = getchar();
  }
  if (ch == '-')
    minus = true;
  else
    result = ch - '0';
  while (true) {
    ch = getchar();
    if (ch < '0' || ch > '9') break;
    result = result * 10 + (ch - '0');
  }
  if (minus)
    return -result;
  else
    return result;
}
int iscompo(int n) {
  int i, sq;
  sq = sqrt(n);
  for (i = 2; i <= sq; i++) {
    if (n % i == 0) return 1;
  }
  return 0;
}
int gcd(int x, int y) {
  if (y == 0) return x;
  return gcd(y, x % y);
}
int pw(int x, int y) {
  if (y == 0) return 1;
  int z = pw(x, y / 2);
  if (y % 2 == 0) return z * z;
  return z * z * x;
}
long long int fast_pow(long long int base, long long int n, long long int M) {
  if (n == 0) return 1;
  if (n == 1) return base;
  long long halfn = fast_pow(base, n / 2, M);
  if (n % 2 == 0)
    return (halfn * halfn) % M;
  else
    return (((halfn * halfn) % M) * base) % M;
}
long long int findMMI_fermat(long long int n, long long int M) {
  return fast_pow(n, M - 2, M);
}
long long int modulo(long long int a, long long int b, long long int n) {
  long long int x = 1, y = a;
  while (b > 0) {
    if (b % 2 == 1) {
      x = (x * y) % n;
    }
    y = (y * y) % n;
    b /= 2;
  }
  return x % n;
}
struct str {
  int x;
  int y;
};
bool my(str lhs, str rhs) { return lhs.x > rhs.x; }
int main() {
  long long int n, i, j, arr[200005][3], min = 99999999, pos = 0, temp = 1;
  long long int ans = 0;
  n = ri();
  for (i = 0; i < n; i++) {
    arr[i][0] = ri();
    arr[i][1] = ri();
    if (arr[i][0] + arr[i][1] < min) {
      min = arr[i][0] + arr[i][1];
      pos = i;
    }
  }
  arr[pos][2] = min;
  for (i = pos - 1; i > -1; i--) {
    if (arr[i][0] > arr[i + 1][2] + 1) {
      temp = 0;
      break;
    }
    if (arr[i][0] + arr[i][1] < arr[i + 1][2] - 1) {
      arr[i][2] = arr[i][0] + arr[i][1];
      j = i;
      while (arr[j + 1][2] - arr[j][2] > 1) {
        arr[j + 1][2] = arr[j][2] + 1;
        j++;
      }
    } else {
      if (arr[i + 1][2] + 1 < arr[i][0] + arr[i][1])
        arr[i][2] = arr[i + 1][2] + 1;
      else
        arr[i][2] = arr[i][0] + arr[i][1];
    }
  }
  if (temp) {
    for (i = pos + 1; i < n; i++) {
      if (arr[i][0] > arr[i - 1][2] + 1) {
        temp = 0;
        break;
      }
      if (arr[i][0] + arr[i][1] < arr[i - 1][2] - 1) {
        arr[i][2] = arr[i][0] + arr[i][1];
        j = i;
        while (arr[j - 1][2] - arr[j][2] > 1) {
          arr[j - 1][2] = arr[j][2] + 1;
          j--;
        }
      } else {
        if (arr[i - 1][2] + 1 < arr[i][0] + arr[i][1])
          arr[i][2] = arr[i - 1][2] + 1;
        else
          arr[i][2] = arr[i][0] + arr[i][1];
      }
    }
    for (i = 0; i < n; i++) {
      if (arr[i][0] > arr[i][2]) {
        temp = 0;
        break;
      } else
        ans += arr[i][2] - arr[i][0];
    }
  }
  if (temp) {
    cout << ans << "\n";
    for (i = 0; i < n; i++) printf("%lld ", arr[i][2]);
  } else
    cout << "-1";
  return 0;
}
