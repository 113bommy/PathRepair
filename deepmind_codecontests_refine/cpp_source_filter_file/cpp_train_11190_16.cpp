#include <bits/stdc++.h>
using namespace std;
const int MAXN = 50;
long long w, m, arr[MAXN];
bool is_ok(long long a, long long b) {
  int s = 0;
  while (b >= a) {
    arr[s] = b % a;
    b /= a;
    s++;
  }
  arr[s] = b;
  for (int i = 0; i <= s; i++) {
    if (arr[i] > 1) {
      if (a - arr[i] == 1) {
        arr[i]++;
      } else {
        return false;
      }
    }
    if (arr[i] >= a) {
      arr[i + 1] += (arr[i] / a);
      arr[i] %= a;
    }
  }
  return true;
}
int main() {
  cin >> w >> m;
  if (is_ok(w, m))
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
