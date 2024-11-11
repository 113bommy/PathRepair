#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n, m;
    cin >> n >> m;
    string arr[n];
    long long i, j, k = 0;
    for (i = 0; i < n; i++) cin >> arr[i];
    vector<long long> v[3 * n * m];
    long long ans = 0;
    for (i = 0; i < n; i += 2) {
      for (j = 0; j < m; j += 2) {
        if (n - i == 1 || m - j == 1) break;
        long long l = 0, t = 0;
        long long x[4], y[4], p[4], q[4];
        if (arr[i][j] == '1') {
          x[l] = i;
          y[l] = j;
          l++;
        } else {
          p[t] = i;
          q[t] = j;
          t++;
        }
        if (arr[i][j + 1] == '1') {
          x[l] = i;
          y[l] = j + 1;
          l++;
        } else {
          p[t] = i;
          q[t] = j + 1;
          t++;
        }
        if (arr[i + 1][j] == '1') {
          x[l] = i + 1;
          y[l] = j;
          l++;
        } else {
          p[t] = i + 1;
          q[t] = j;
          t++;
        }
        if (arr[i + 1][j + 1] == '1') {
          x[l] = i + 1;
          y[l] = j + 1;
          l++;
        } else {
          p[t] = i + 1;
          q[t] = j + 1;
          t++;
        }
        if (l == 4) {
          ans += 4;
          v[k].push_back(x[0]);
          v[k].push_back(y[0]);
          v[k].push_back(x[1]);
          v[k].push_back(y[1]);
          v[k].push_back(x[2]);
          v[k].push_back(y[2]);
          k++;
          v[k].push_back(x[0]);
          v[k].push_back(y[0]);
          v[k].push_back(x[1]);
          v[k].push_back(y[1]);
          v[k].push_back(x[3]);
          v[k].push_back(y[3]);
          k++;
          v[k].push_back(x[0]);
          v[k].push_back(y[0]);
          v[k].push_back(x[2]);
          v[k].push_back(y[2]);
          v[k].push_back(x[3]);
          v[k].push_back(y[3]);
          k++;
          v[k].push_back(x[2]);
          v[k].push_back(y[2]);
          v[k].push_back(x[1]);
          v[k].push_back(y[1]);
          v[k].push_back(x[3]);
          v[k].push_back(y[3]);
          k++;
        }
        if (l == 3) {
          ans += 1;
          v[k].push_back(x[0]);
          v[k].push_back(y[0]);
          v[k].push_back(x[1]);
          v[k].push_back(y[1]);
          v[k].push_back(x[2]);
          v[k].push_back(y[2]);
          k++;
        }
        if (l == 2) {
          ans += 2;
          v[k].push_back(x[0]);
          v[k].push_back(y[0]);
          v[k].push_back(p[0]);
          v[k].push_back(q[0]);
          v[k].push_back(p[1]);
          v[k].push_back(q[1]);
          k++;
          v[k].push_back(x[1]);
          v[k].push_back(y[1]);
          v[k].push_back(p[0]);
          v[k].push_back(q[0]);
          v[k].push_back(p[1]);
          v[k].push_back(q[1]);
          k++;
        }
        if (l == 1) {
          ans += 3;
          v[k].push_back(x[0]);
          v[k].push_back(y[0]);
          v[k].push_back(p[0]);
          v[k].push_back(q[0]);
          v[k].push_back(p[1]);
          v[k].push_back(q[1]);
          k++;
          v[k].push_back(x[0]);
          v[k].push_back(y[0]);
          v[k].push_back(p[1]);
          v[k].push_back(q[1]);
          v[k].push_back(p[2]);
          v[k].push_back(q[2]);
          k++;
          v[k].push_back(x[0]);
          v[k].push_back(y[0]);
          v[k].push_back(p[2]);
          v[k].push_back(q[2]);
          v[k].push_back(p[1]);
          v[k].push_back(q[1]);
          k++;
        }
      }
    }
    if (n % 2 != 0) {
      i = n - 2;
      for (j = 0; j < m; j += 2) {
        if (m - j == 1) break;
        long long l = 0, t = 0;
        long long x[4], y[4], p[4], q[4];
        p[t] = i;
        q[t] = j;
        t++;
        p[t] = i;
        q[t] = j + 1;
        t++;
        if (arr[i + 1][j] == '1') {
          x[l] = i + 1;
          y[l] = j;
          l++;
        } else {
          p[t] = i + 1;
          q[t] = j;
          t++;
        }
        if (arr[i + 1][j + 1] == '1') {
          x[l] = i + 1;
          y[l] = j + 1;
          l++;
        } else {
          p[t] = i + 1;
          q[t] = j + 1;
          t++;
        }
        if (l == 4) {
          ans += 4;
          v[k].push_back(x[0]);
          v[k].push_back(y[0]);
          v[k].push_back(x[1]);
          v[k].push_back(y[1]);
          v[k].push_back(x[2]);
          v[k].push_back(y[2]);
          k++;
          v[k].push_back(x[0]);
          v[k].push_back(y[0]);
          v[k].push_back(x[1]);
          v[k].push_back(y[1]);
          v[k].push_back(x[3]);
          v[k].push_back(y[3]);
          k++;
          v[k].push_back(x[0]);
          v[k].push_back(y[0]);
          v[k].push_back(x[2]);
          v[k].push_back(y[2]);
          v[k].push_back(x[3]);
          v[k].push_back(y[3]);
          k++;
          v[k].push_back(x[2]);
          v[k].push_back(y[2]);
          v[k].push_back(x[1]);
          v[k].push_back(y[1]);
          v[k].push_back(x[3]);
          v[k].push_back(y[3]);
          k++;
        }
        if (l == 3) {
          ans += 1;
          v[k].push_back(x[0]);
          v[k].push_back(y[0]);
          v[k].push_back(x[1]);
          v[k].push_back(y[1]);
          v[k].push_back(x[2]);
          v[k].push_back(y[2]);
          k++;
        }
        if (l == 2) {
          ans += 2;
          v[k].push_back(x[0]);
          v[k].push_back(y[0]);
          v[k].push_back(p[0]);
          v[k].push_back(q[0]);
          v[k].push_back(p[1]);
          v[k].push_back(q[1]);
          k++;
          v[k].push_back(x[1]);
          v[k].push_back(y[1]);
          v[k].push_back(p[0]);
          v[k].push_back(q[0]);
          v[k].push_back(p[1]);
          v[k].push_back(q[1]);
          k++;
        }
        if (l == 1) {
          ans += 3;
          v[k].push_back(x[0]);
          v[k].push_back(y[0]);
          v[k].push_back(p[0]);
          v[k].push_back(q[0]);
          v[k].push_back(p[1]);
          v[k].push_back(q[1]);
          k++;
          v[k].push_back(x[0]);
          v[k].push_back(y[0]);
          v[k].push_back(p[1]);
          v[k].push_back(q[1]);
          v[k].push_back(p[2]);
          v[k].push_back(q[2]);
          k++;
          v[k].push_back(x[0]);
          v[k].push_back(y[0]);
          v[k].push_back(p[2]);
          v[k].push_back(q[2]);
          v[k].push_back(p[1]);
          v[k].push_back(q[1]);
          k++;
        }
      }
    }
    if (m % 2 != 0) {
      j = m - 2;
      for (i = 0; i < n; i += 2) {
        if (n - i == 1) break;
        long long l = 0, t = 0;
        long long x[4], y[4], p[4], q[4];
        p[t] = i;
        q[t] = j;
        t++;
        if (arr[i][j + 1] == '1') {
          x[l] = i;
          y[l] = j + 1;
          l++;
        } else {
          p[t] = i;
          q[t] = j + 1;
          t++;
        }
        p[t] = i + 1;
        q[t] = j;
        t++;
        if (arr[i + 1][j + 1] == '1') {
          x[l] = i + 1;
          y[l] = j + 1;
          l++;
        } else {
          p[t] = i + 1;
          q[t] = j + 1;
          t++;
        }
        if (l == 4) {
          ans += 4;
          v[k].push_back(x[0]);
          v[k].push_back(y[0]);
          v[k].push_back(x[1]);
          v[k].push_back(y[1]);
          v[k].push_back(x[2]);
          v[k].push_back(y[2]);
          k++;
          v[k].push_back(x[0]);
          v[k].push_back(y[0]);
          v[k].push_back(x[1]);
          v[k].push_back(y[1]);
          v[k].push_back(x[3]);
          v[k].push_back(y[3]);
          k++;
          v[k].push_back(x[0]);
          v[k].push_back(y[0]);
          v[k].push_back(x[2]);
          v[k].push_back(y[2]);
          v[k].push_back(x[3]);
          v[k].push_back(y[3]);
          k++;
          v[k].push_back(x[2]);
          v[k].push_back(y[2]);
          v[k].push_back(x[1]);
          v[k].push_back(y[1]);
          v[k].push_back(x[3]);
          v[k].push_back(y[3]);
          k++;
        }
        if (l == 3) {
          ans += 1;
          v[k].push_back(x[0]);
          v[k].push_back(y[0]);
          v[k].push_back(x[1]);
          v[k].push_back(y[1]);
          v[k].push_back(x[2]);
          v[k].push_back(y[2]);
          k++;
        }
        if (l == 2) {
          ans += 2;
          v[k].push_back(x[0]);
          v[k].push_back(y[0]);
          v[k].push_back(p[0]);
          v[k].push_back(q[0]);
          v[k].push_back(p[1]);
          v[k].push_back(q[1]);
          k++;
          v[k].push_back(x[1]);
          v[k].push_back(y[1]);
          v[k].push_back(p[0]);
          v[k].push_back(q[0]);
          v[k].push_back(p[1]);
          v[k].push_back(q[1]);
          k++;
        }
        if (l == 1) {
          ans += 3;
          v[k].push_back(x[0]);
          v[k].push_back(y[0]);
          v[k].push_back(p[0]);
          v[k].push_back(q[0]);
          v[k].push_back(p[1]);
          v[k].push_back(q[1]);
          k++;
          v[k].push_back(x[0]);
          v[k].push_back(y[0]);
          v[k].push_back(p[1]);
          v[k].push_back(q[1]);
          v[k].push_back(p[2]);
          v[k].push_back(q[2]);
          k++;
          v[k].push_back(x[0]);
          v[k].push_back(y[0]);
          v[k].push_back(p[2]);
          v[k].push_back(q[2]);
          v[k].push_back(p[1]);
          v[k].push_back(q[1]);
          k++;
        }
      }
    }
    if (n % 2 != 0 && m % 2 != 0) {
      i = n - 2;
      j = m - 2;
      long long l = 0, t = 0;
      long long x[4], y[4], p[4], q[4];
      p[t] = i;
      q[t] = j;
      t++;
      p[t] = i + 1;
      q[t] = j;
      t++;
      p[t] = i;
      q[t] = j + 1;
      t++;
      if (arr[i + 1][j + 1] == '1') {
        x[l] = i + 1;
        y[l] = j + 1;
        l++;
      } else {
        p[t] = i + 1;
        q[t] = j + 1;
        t++;
      }
      if (l == 4) {
        ans += 4;
        v[k].push_back(x[0]);
        v[k].push_back(y[0]);
        v[k].push_back(x[1]);
        v[k].push_back(y[1]);
        v[k].push_back(x[2]);
        v[k].push_back(y[2]);
        k++;
        v[k].push_back(x[0]);
        v[k].push_back(y[0]);
        v[k].push_back(x[1]);
        v[k].push_back(y[1]);
        v[k].push_back(x[3]);
        v[k].push_back(y[3]);
        k++;
        v[k].push_back(x[0]);
        v[k].push_back(y[0]);
        v[k].push_back(x[2]);
        v[k].push_back(y[2]);
        v[k].push_back(x[3]);
        v[k].push_back(y[3]);
        k++;
        v[k].push_back(x[2]);
        v[k].push_back(y[2]);
        v[k].push_back(x[1]);
        v[k].push_back(y[1]);
        v[k].push_back(x[3]);
        v[k].push_back(y[3]);
        k++;
      }
      if (l == 3) {
        ans += 1;
        v[k].push_back(x[0]);
        v[k].push_back(y[0]);
        v[k].push_back(x[1]);
        v[k].push_back(y[1]);
        v[k].push_back(x[2]);
        v[k].push_back(y[2]);
        k++;
      }
      if (l == 2) {
        ans += 2;
        v[k].push_back(x[0]);
        v[k].push_back(y[0]);
        v[k].push_back(p[0]);
        v[k].push_back(q[0]);
        v[k].push_back(p[1]);
        v[k].push_back(q[1]);
        k++;
        v[k].push_back(x[1]);
        v[k].push_back(y[1]);
        v[k].push_back(p[0]);
        v[k].push_back(q[0]);
        v[k].push_back(p[1]);
        v[k].push_back(q[1]);
        k++;
      }
      if (l == 1) {
        ans += 3;
        v[k].push_back(x[0]);
        v[k].push_back(y[0]);
        v[k].push_back(p[0]);
        v[k].push_back(q[0]);
        v[k].push_back(p[1]);
        v[k].push_back(q[1]);
        k++;
        v[k].push_back(x[0]);
        v[k].push_back(y[0]);
        v[k].push_back(p[1]);
        v[k].push_back(q[1]);
        v[k].push_back(p[2]);
        v[k].push_back(q[2]);
        k++;
        v[k].push_back(x[0]);
        v[k].push_back(y[0]);
        v[k].push_back(p[2]);
        v[k].push_back(q[2]);
        v[k].push_back(p[1]);
        v[k].push_back(q[1]);
        k++;
      }
    }
    cout << ans << endl;
    for (i = 0; i < ans; i++) {
      for (j = 0; j < 6; j++) {
        cout << v[i][j] + 1 << " ";
      }
      cout << endl;
    }
  }
}
