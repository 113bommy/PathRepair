#include <bits/stdc++.h>
using namespace std;
struct _ {
  _() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin.exceptions(istream::failbit | istream::badbit);
  }
} _;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
template <class T, class second>
void smax(T& a, const second& b) {
  if (b > a) a = b;
}
template <class T, class second>
void smin(T& a, const second& b) {
  if (b < a) a = b;
}
template <class T, class second>
T pop_begin(second& a) {
  auto it = a.begin();
  T ret = *it;
  a.erase(it);
  return ret;
}
signed main() {
  int N;
  cin >> N;
  unsigned int A = 0, B = 0;
  for (int i = 0; i < (N); ++i) {
    unsigned int x;
    cin >> x;
    A += x;
  }
  for (int i = 0; i < (N - 1); ++i) {
    unsigned int x;
    cin >> x;
    A -= x;
    B += x;
  }
  for (int i = 0; i < (N - 2); ++i) {
    unsigned int x;
    cin >> x;
    B -= x;
  }
  cout << A << ' ' << B << endl;
}
