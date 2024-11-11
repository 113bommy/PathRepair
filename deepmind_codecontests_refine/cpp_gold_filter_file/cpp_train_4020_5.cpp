#include <bits/stdc++.h>
using namespace std;
template <class T>
void _R(T &x) {
  cin >> x;
}
void _R(int &x) { scanf("%d", &x); }
void _R(long long &x) { scanf("%lld", &x); }
void _R(double &x) { scanf("%lf", &x); }
void _R(char &x) { scanf(" %c", &x); }
void _R(char *x) { scanf("%s", x); }
void R() {}
template <class T, class... U>
void R(T &head, U &...tail) {
  _R(head);
  R(tail...);
}
template <class T>
void _W(const T &x) {
  cout << x;
}
void _W(const int &x) { printf("%d", x); }
void _W(const long long &x) { printf("%lld", x); }
void _W(const double &x) { printf("%.16f", x); }
void _W(const char &x) { putchar(x); }
void _W(const char *x) { printf("%s", x); }
template <class T, class U>
void _W(const pair<T, U> &x) {
  _W(x.first);
  putchar(' ');
  _W(x.second);
}
template <class T>
void _W(const vector<T> &x) {
  for (auto i = x.begin(); i != x.end(); _W(*i++))
    if (i != x.cbegin()) putchar(' ');
}
void W() {}
template <class T, class... U>
void W(const T &head, const U &...tail) {
  _W(head);
  putchar(sizeof...(tail) ? ' ' : '\n');
  W(tail...);
}
int MOD = 1e9 + 7;
void ADD(long long &x, long long v) {
  x = (x + v) % MOD;
  if (x < 0) x += MOD;
}
const int SIZE = 1e6 + 10;
int get_bit(int x, int v) { return (x >> v) & 1; }
int qq(vector<int> AA) {
  if (((int)(AA).size()) == 0) return 0;
  for (int i = 0; i < (((int)(AA).size())); ++i) AA[i]++;
  W("?", ((int)(AA).size()), AA);
  fflush(stdout);
  int x;
  R(x);
  return x;
}
int main() {
  int n, x, y;
  R(n, x, y);
  int sp = 9;
  for (int i = 0; i < (9); ++i) {
    vector<int> AA;
    int expect = 0;
    for (int j = 0; j < (n); ++j) {
      if (get_bit(j, i) == 0) {
        AA.push_back(j);
        expect ^= x;
      }
    }
    expect ^= x ^ y;
    if (qq(AA) == expect) {
      sp = i;
      break;
    }
  }
  int res[2] = {0, 1 << sp};
  for (int i = 0; i < (10); ++i) {
    if (i < sp) {
      vector<int> AA;
      int expect = 0;
      for (int j = 0; j < (n); ++j) {
        if (get_bit(j, i) == 0 && get_bit(j, sp) == 0) {
          AA.push_back(j);
          expect ^= x;
        }
      }
      expect ^= x ^ y;
      if (qq(AA) != expect) {
        res[0] ^= 1 << i;
        res[1] ^= 1 << i;
      }
    } else if (i > sp) {
      {
        vector<int> AA;
        int expect = 0;
        for (int j = 0; j < (n); ++j) {
          if (get_bit(j, i) == 0 && get_bit(j, sp) == 0) {
            AA.push_back(j);
            expect ^= x;
          }
        }
        expect ^= x ^ y;
        if (qq(AA) != expect) {
          res[0] ^= 1 << i;
        }
      }
      {
        vector<int> AA;
        int expect = 0;
        for (int j = 0; j < (n); ++j) {
          if (get_bit(j, i) == 0 && get_bit(j, sp) == 1) {
            AA.push_back(j);
            expect ^= x;
          }
        }
        expect ^= x ^ y;
        if (qq(AA) != expect) res[1] ^= 1 << i;
      }
    }
  }
  sort(res, res + 2);
  W("!", res[0] + 1, res[1] + 1);
  fflush(stdout);
  return 0;
}
