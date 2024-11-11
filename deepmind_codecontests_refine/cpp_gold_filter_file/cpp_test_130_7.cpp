#include <bits/stdc++.h>
using namespace std;
const long long N = 1e4 + 10;
long long a[N];
long long ans[N];
long long ind1, ind0;
long long find1, find0;
long long query(long long x, long long y, long long z) {
  cout << "? " << x << " " << y << " " << z << endl;
  long long tmp;
  cin >> tmp;
  return tmp;
}
void solve() {
  long long n;
  cin >> n;
  ind1 = ind0 = -1;
  find0 = find1 = -1;
  for (long long i = 1; i <= n; ++i) ans[i] = a[i] = -1;
  for (long long i = 1; i <= n - 2; i += 3) {
    a[i] = query(i, i + 1, i + 2);
  }
  for (long long i = 1; i <= n - 5; i += 3) {
    if (a[i] != a[i + 3]) {
      a[i + 1] = query(i + 1, i + 2, i + 3);
      a[i + 2] = query(i + 2, i + 3, i + 4);
      for (long long j = i; j <= i + 2; ++j) {
        if (a[j] != a[j + 1]) {
          if (a[j] == 0) {
            ind1 = j + 3;
            ind0 = j;
            ans[j + 3] = 1;
            ans[j] = 0;
          } else {
            ind0 = j + 3;
            ind1 = j;
            ans[j + 3] = 0;
            ans[j] = 1;
          }
        }
      }
      break;
    }
  }
  for (long long i = 1; i + 2 <= n; i += 3) {
    if (ind0 <= i + 2 && ind0 >= i) continue;
    if (ind1 <= i + 2 && ind1 >= i) continue;
    if (a[i] == 0) {
      long long ab1 = query(i, i + 1, ind1);
      if (ab1 == 1) {
        ans[i + 2] = 0;
        long long bc1 = query(i + 1, i + 2, ind1);
        if (bc1 == 1) {
          ans[i + 1] = 1;
          ans[i] = 0;
        } else {
          ans[i] = 1;
          ans[i + 1] = 0;
        }
      } else {
        ans[i + 1] = ans[i] = 0;
        long long bc1 = query(i + 1, i + 2, ind1);
        if (bc1 == 1) {
          ans[i + 2] = 1;
        } else
          ans[i + 2] = 0;
      }
    } else {
      long long ab0 = query(i, i + 1, ind0);
      if (ab0 == 0) {
        ans[i + 2] = 1;
        long long bc0 = query(i + 1, i + 2, ind0);
        if (bc0 == 0) {
          ans[i + 1] = 0;
          ans[i] = 1;
        } else {
          ans[i] = 0;
          ans[i + 1] = 1;
        }
      } else {
        ans[i + 1] = ans[i] = 1;
        long long bc0 = query(i + 1, i + 2, ind0);
        if (bc0 == 0) {
          ans[i + 2] = 0;
        } else
          ans[i + 2] = 1;
      }
    }
  }
  for (long long i = 1; i <= n; ++i) {
    if (ans[i] == -1) {
      ans[i] = query(ind0, ind1, i);
    }
  }
  vector<long long> vec;
  for (long long i = 1; i <= n; ++i)
    if (ans[i] == 0) {
      vec.push_back(i);
    }
  cout << "! " << vec.size() << " ";
  for (auto i : vec) {
    cout << i << " ";
  }
  cout << endl;
  return;
}
signed main() {
  long long T;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
