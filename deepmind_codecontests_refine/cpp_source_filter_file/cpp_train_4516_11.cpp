#include <bits/stdc++.h>
using namespace std;
struct debugger {
  template <typename T>
  debugger& operator,(const T& v) {
    cerr << v << " ";
    return *this;
  }
} dbg;
void debugarr(int* arr, int n) {
  cout << "[";
  for (int i = 0; i < n; i++) cout << arr[i] << " ";
  cout << "]" << endl;
}
int main() {
  int m;
  scanf("%d", &m);
  vector<int> q;
  int x;
  for (int i = 0; i <= m - 1; i++) {
    scanf("%d", &x);
    q.push_back(x);
  }
  int n;
  scanf("%d", &n);
  vector<int> a;
  for (int i = 0; i <= n - 1; i++) {
    scanf("%d", &x);
    a.push_back(x);
  }
  sort(q.begin(), q.end());
  sort(a.begin(), a.end());
  int val = q[0];
  int le = 0, ri = n - 1;
  long long ans = 0;
  while (le <= ri) {
    for (int i = 0; i < val && le <= ri; i++) {
      ans += a[ri];
      ri--;
    }
    le += 2;
  }
  printf("%lld\n", ans);
  return 0;
}
