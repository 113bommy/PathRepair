#include <bits/stdc++.h>
using namespace std;
void print4(long long l) {
  cout << 0 << endl << 4 << endl;
  for (long long i = l; i < l + 5; i++)
    if (i % 2 == 0 && i + 1 < l + 5) cout << i << ' ' << i + 1 << ' ';
  cout << endl;
}
void print2(long long l) {
  cout << 1 << endl << 2 << endl;
  for (long long i = l; i < l + 3; i++)
    if (i % 2 == 0) {
      cout << i << ' ' << i + 1 << endl;
      break;
    }
}
void print1(long long l) { cout << l << endl << 1 << endl << l << endl; }
int main() {
  ios_base::sync_with_stdio(false);
  long long l, r, k;
  cin >> l >> r >> k;
  long long range = r - l + 1;
  if (range >= 5) {
    if (k >= 4)
      print4(l);
    else if (k >= 2) {
      bool done = false;
      if (k >= 3) {
        for (long long i = 1; i < 50; i++) {
          long long a = (1LL << i) + (1LL << (i - 1));
          long long b = a - 1;
          long long c = (1LL << i) - 1;
          if (a <= r && c >= l) {
            cout << 0 << endl << 3 << endl << a << ' ' << b << ' ' << c << endl;
            done = true;
            break;
          }
        }
      }
      if (!done) print2(l);
    } else
      print1(l);
  } else if (range == 4) {
    if (l % 2 == 0 && k >= 4)
      print4(l);
    else if (k >= 2) {
      bool done = false;
      if (k >= 3) {
        for (long long i = 1; i < 50; i++) {
          long long a = (1LL << i) + (1LL << (i - 1));
          long long b = a - 1;
          long long c = (1LL << i) - 1;
          if (a <= r && c >= l) {
            cout << 0 << endl << 3 << endl << a << ' ' << b << ' ' << c << endl;
            done = true;
            break;
          }
        }
      }
      if (!done) print2(l);
    } else
      print1(l);
  } else if (range == 3) {
    if (k >= 2) {
      if ((l ^ (l + 1) ^ (l + 2)) == 0)
        cout << 0 << endl
             << 3 << endl
             << l << ' ' << l + 1 << ' ' << l + 2 << endl;
      else
        print2(l);
    } else
      print1(l);
  } else if (range == 2) {
    if (k >= 2 && (l ^ r) < l) {
      cout << (l ^ r) << endl << 2 << endl << l << ' ' << r << endl;
    } else
      print1(l);
  } else if (range == 1) {
    print1(l);
  }
  return 0;
}
