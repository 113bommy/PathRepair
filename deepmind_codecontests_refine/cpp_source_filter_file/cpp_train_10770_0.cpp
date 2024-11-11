#include <bits/stdc++.h>
using namespace std;
long long nC2(long long a) {
  long long t = a;
  t *= t - 1;
  t /= 2;
  return t;
}
int arr[1000001];
int main() {
  long long n, l, x, y;
  bool fx = 0, fy = 0;
  int a = 2;
  cin >> n >> l >> x >> y;
  map<long long, int> make_pair;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    make_pair[arr[i]] = 1;
  }
  for (int i = 0; i < n && a; i++) {
    if (!fx) {
      if (make_pair[x + arr[i]] == 1 || make_pair[arr[i] - x] == 1) {
        fx = 1;
        a--;
      }
    }
    if (!fy) {
      if (make_pair[y + arr[i]] == 1 || make_pair[arr[i] - y] == 1) {
        fy = 1;
        a--;
      }
    }
  }
  if (a == 0)
    cout << a << endl;
  else {
    if (a == 1) {
      cout << a << endl;
      if (fx)
        cout << y << endl;
      else
        cout << x << endl;
    } else {
      bool nf = 1;
      long long X;
      for (int i = 0; i < n && nf; i++) {
        long long z = arr[i] + x;
        if (z >= 0 && z <= l) {
          if (make_pair[z + y] == 1 || make_pair[z - y] == 1) {
            nf = 1;
            X = z;
            break;
          }
        }
        z = arr[i] - x;
        if (z >= 0 && z <= l) {
          if (make_pair[z + y] == 1 || make_pair[z - y] == 1) {
            nf = 1;
            X = z;
            break;
          }
        }
      }
      if (nf == 0) {
        cout << 1 << endl;
        cout << X << endl;
      } else {
        cout << 2 << endl;
        cout << x << ' ';
        cout << y << endl;
      }
    }
  }
  cin >> n;
  return 0;
}
