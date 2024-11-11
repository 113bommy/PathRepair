#include <bits/stdc++.h>
using namespace std;
int k[200005];
int aux[200005];
string a, b;
bool check(int x) {
  int j = 0;
  for (int i = 0; i < a.size(); i++) {
    if (aux[i] <= x) continue;
    if (a[i] == b[j]) {
      j++;
      if (j == b.size()) return true;
    }
  }
  return false;
}
int solve(int low, int high) {
  while (low <= high) {
    int mid = (low + high) / 2;
    if (check(mid) == true) {
      low = mid + 1;
    } else {
      if (check(mid - 1) == true)
        return mid - 1;
      else {
        high = mid - 1;
      }
    }
  }
  return -1;
}
int main() {
  int i;
  cin >> a >> b;
  int n = a.size();
  for (i = 0; i < n; i++) {
    cin >> k[i];
    k[i]--;
    aux[k[i]] = i;
  }
  cout << solve(0, n - 1) + 1;
  return 0;
}
