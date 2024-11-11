#include <bits/stdc++.h>
using namespace std;
void fast() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
const long long N = 1005;
long long dr[4] = {0, 0, 1, -1};
long long dc[4] = {1, -1, 0, 0};
long long ddr[8] = {0, 0, 1, -1, 1, -1, 1, -1};
long long ddc[8] = {1, -1, 0, 0, 1, -1, -1, 1};
long long ddr1[8] = {1, 1, -1, -1, 2, 2, -2, -2};
long long ddc1[8] = {2, -2, 2, -2, 1, -1, 1, -1};
long long a[200003], cons[200003], cons1[200003];
void add1(long long x, long long y) { cons[max(x, y)] = min(x, y); }
void add2(long long x, long long y) { cons1[max(x, y)] = min(x, y); }
int32_t main() {
  fast();
  long long n;
  cin >> n;
  for (long long i = 1; i < n + 2; i++) {
    cin >> a[i];
  }
  bool ok = 0;
  long long pos = -1;
  for (long long i = 2; i < n + 2; i++) {
    if (a[i] > 1 && a[i - 1] > 1) {
      ok = 1;
      pos = i - 1;
    }
  }
  if (ok == 0) {
    cout << "perfect";
    return 0;
  }
  cout << "ambiguous\n";
  long long i = 1;
  long long temp;
  for (i = 1; i <= n; i++) {
    add1(i, i + 1);
  }
  i = n + 2;
  for (long long j = 2; j <= n + 1; j++) {
    if (a[j] > 1) {
      temp = a[j] - 1;
      for (long long k = 0; k < temp; k++) {
        add1(i, j - 1);
        i++;
      }
    }
  }
  i = 1;
  long long akh = -1;
  for (i = 1; i <= n; i++) {
    add2(i, i + 1);
  }
  i = n + 2;
  for (long long j = 2; j <= n + 1; j++) {
    if (a[j] > 1) {
      if (j == pos) {
        temp = a[j] - 1;
        for (long long k = 0; k < temp; k++) {
          add2(i, j - 1);
          akh = i;
          i++;
        }
      } else if (j == pos + 1) {
        add2(akh, i);
        i++;
        long long temp = a[j] - 2;
        for (long long k = 0; k < temp; k++) {
          add1(i, j - 1);
          i++;
        }
      } else {
        long long temp = a[j] - 1;
        for (long long k = 0; k < temp; k++) {
          add1(i, j - 1);
          i++;
        }
      }
    }
  }
  cout << "0 ";
  for (i = 2;; i++) {
    if (cons[i] == 0) {
      cout << "\n";
      break;
    } else
      cout << cons[i] << " ";
  }
  cout << "0 ";
  for (i = 2;; i++) {
    if (cons1[i] == 0) {
      cout << "\n";
      break;
    } else
      cout << cons1[i] << " ";
  }
}
