#include <bits/stdc++.h>
using namespace std;
long long int d, x, y;
long long int LIM = 1000000007;
bool is_prime(int n) {
  bool prime[n + 1];
  memset(prime, true, sizeof(prime));
  for (int p = 2; p * p <= n; p++) {
    if (prime[p]) {
      for (int i = p * p; i <= n; i += p) prime[i] = false;
    }
  }
  return prime[n];
}
long long int bsearch(vector<long long int> v, long long int k) {
  long long int lo = 0, hi = v.size() - 1;
  long long int mid = (lo + hi) / 2;
  while (lo <= hi) {
    mid = (lo + hi) / 2;
    if (k > v[mid])
      lo = mid + 1;
    else if (k < v[mid])
      hi = mid - 1;
    else
      return mid;
  }
}
long long int power(long long int a, long long int b) {
  if (b == 0)
    return 1;
  else if (b == 1)
    return a;
  else {
    if (b % 2 == 0)
      return power((a * a) % LIM, b / 2);
    else
      return a * power((a * a) % LIM, (b - 1) / 2);
  }
}
void gcd(long long int a, long long int b) {
  if (b == 0) {
    d = a;
    x = 1;
    y = 0;
  } else {
    gcd(b, a % b);
    long long int t = x;
    x = y;
    y = t - (a / b) * y;
  }
}
long long int MMI(long long int n) {
  gcd(n, LIM);
  return (x % LIM + LIM) % LIM;
}
void solve() {
  long long int h;
  cin >> h;
  ;
  long long int w;
  cin >> w;
  ;
  char arr[h][w];
  long long int fi = -1, fj = -1, t = 1;
  for (unsigned long long int i = 0; i <= h - 1; i++) {
    for (unsigned long long int j = 0; j <= w - 1; j++) {
      cin >> arr[i][j];
      if (arr[i][j] == '*' && t == 1) {
        fi = i;
        fj = j;
        t++;
      }
    }
  }
  if ((fi == -1 && fj == -1) || (fj == 0) || fi == h - 1 || fj == w - 1 ||
      fi == h - 2)
    cout << "NO";
  else {
    for (unsigned long long int i = fi; i <= h - 2; i++) {
      if ((arr[i][fj] == '*' || arr[i][fj] == '+') &&
          (arr[i + 1][fj] == '*' || arr[i + 1][fj] == '+')) {
        arr[i][fj] = '+';
        arr[i + 1][fj] = '+';
      }
    }
    long long int t = -1;
    for (unsigned long long int i = fi; i <= h - 1; i++) {
      if (arr[i][fj] == '+' && arr[i][fj + 1] == '*' && arr[i][fj - 1] == '*') {
        t = i;
        break;
      }
    }
    if (t == -1)
      cout << "NO";
    else {
      for (unsigned long long int j = 0; j <= w - 2; j++) {
        if ((arr[t][j] == '*' || arr[t][j] == '+') &&
            (arr[t][j + 1] == '*' || arr[t][j + 1] == '+') &&
            (arr[t + 1][j] == '*' || arr[t + 1][j] == '+')) {
          arr[t][j] = '+';
          arr[t][j + 1] = '+';
        } else if ((arr[t][j] == '*' || arr[t][j] == '+') &&
                   (arr[t][j + 1] == '.'))
          break;
      }
      for (unsigned long long int i = 0; i <= h - 1; i++) {
        for (unsigned long long int j = 0; j <= w - 1; j++) {
          if (arr[i][j] == '*') {
            cout << "NO";
            t = -1;
            break;
          }
        }
        if (t == -1) break;
      }
      if (t != -1) cout << "YES";
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int m = 1;
  while (m--) solve();
}
