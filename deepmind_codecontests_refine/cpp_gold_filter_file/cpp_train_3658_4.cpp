#include <bits/stdc++.h>
using namespace std;
template <class A, class B>
inline bool mina(A &first, B second) {
  return (first > second) ? (first = second, 1) : 0;
}
template <class A, class B>
inline bool maxa(A &first, B second) {
  return (first < second) ? (first = second, 1) : 0;
}
const int MAXN = 1005;
int N;
int in[MAXN];
int ans[MAXN];
map<int, int> mem;
int solve(int first) {
  if (mem.count(first)) {
    return mem[first];
  }
  int ret = 1;
  for (int i = 2; i <= first / 2; i++) {
    if (first % i == 0) {
      maxa(ret, i);
    }
  }
  return mem[first] = ret;
}
int main() {
  cin >> N;
  for (int i = 0; (i) < (N); ++(i)) {
    cin >> in[i];
  }
  for (int i = 0; (i) < (N); ++(i)) {
    int a = in[i];
    int num_one = __builtin_popcount(a);
    int f = (1 << (num_one)) - 1;
    if (a == f) {
      ans[i] = solve(in[i]);
    } else {
      int cnt = 0;
      while (a) {
        a /= 2;
        cnt++;
      }
      ans[i] = (1 << cnt) - 1;
    }
  }
  for (int i = 0; (i) < (N); ++(i)) {
    cout << ans[i] << endl;
  }
  return 0;
}
