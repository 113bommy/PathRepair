#include <bits/stdc++.h>
using namespace std;
int a[1002] = {0};
void prime_algo(int n) {
  for (int i = 3; i < n; i += 2) {
    a[i] = 1;
  }
  for (int i = 3; i < n; i = i + 2) {
    if (a[i] == 1) {
      for (int p = i * i; p < n; p = p + i) {
        a[p] = 0;
      }
    }
  }
  a[0] = a[1] = 0;
  a[2] = 1;
  return;
}
bool check(int n, int k) {
  if (k == 0) return true;
  if (n <= 11) return false;
  set<int> s;
  int cnt = 0, sum = 2;
  for (int i = 3; i <= n; i++) {
    if (a[i] == 1 && s.find(i - 1) != s.end()) {
      k--;
      if (k == 0) return true;
    }
    if (a[i] == 1) {
      sum = sum + i;
      cnt++;
      if (cnt == 1) {
        s.insert(sum);
        cnt = 0;
        sum = i;
      }
    }
  }
  return false;
}
int main() {
  int n, k;
  cin >> n >> k;
  memset(a, 0, sizeof(a));
  prime_algo(n);
  if (check(n, k))
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
