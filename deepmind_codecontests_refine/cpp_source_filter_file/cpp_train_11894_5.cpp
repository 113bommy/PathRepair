#include <bits/stdc++.h>
using namespace std;
void err(istream_iterator<string> it) {}
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
  cerr << *it << " = " << a << endl;
  err(++it, args...);
}
bool CMP(int a, int b) { return a > b; }
bool CMPpair(pair<long long int, long long int> a,
             pair<long long int, long long int> b) {
  if (a.first != b.first) return a.first < b.first;
  return a.second < b.second;
}
int main() {
  long long int t, ti = 0;
  cin >> t;
  while ((ti++) != t) {
    long long int n;
    cin >> n;
    if (n < 4)
      printf("-1");
    else {
      for (int i = n; i >= 1; i--) {
        if (i % 2) printf("%d ", i);
      }
      printf("4 2 ");
      for (int i = 6; i <= n; i += 2) printf("%d ", i);
      printf("\n");
    }
  }
}
