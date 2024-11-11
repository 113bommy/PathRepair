#include <bits/stdc++.h>
using namespace std;
int NOD(int n1, int n2) {
  int div;
  if (n1 == n2) return n1;
  int d = n1 - n2;
  if (d < 0) {
    d = -d;
    div = NOD(n1, d);
  } else {
    div = NOD(n2, d);
  }
  return div;
}
int NOK(int n1, int n2) { return n1 * n2 / NOD(n1, n2); }
struct ex {
  int day;
  int day2write;
  bool used;
  bool operator()(ex e1, ex e2) const { return e1.day < e2.day; }
};
int main() {
  std::ios::sync_with_stdio(false);
  int n;
  cin >> n;
  long long int* a = new long long int[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  int* ptrs = new int[4];
  n -= 1;
  for (int i = 0; i < 4; i++) ptrs[i] = n - i;
  do {
    bool found = true;
    for (int i = 0; i < 3; i++) {
      int ind2 = (i + 1) % 3;
      int ind3 = (i + 2) % 3;
      long long int sum = a[ptrs[ind2]] + a[ptrs[ind3]];
      if (sum <= a[ptrs[i]]) {
        ptrs[i] = ptrs[3];
        --ptrs[3];
        found = false;
        break;
      }
    }
    if (found) {
      cout << "YES";
      return 0;
    }
  } while (ptrs[3] >= 0);
  cout << "NO";
  return 0;
}
