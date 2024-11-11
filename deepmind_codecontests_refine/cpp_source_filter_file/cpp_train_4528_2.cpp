#include <bits/stdc++.h>
using namespace std;
int n, has[3001], a[3001];
long int cost = 0;
int find_next(int ver) {
  for (int i = ver + 1; i < 3001; i++) {
    if (has[i] == 0) {
      return i;
    }
  }
}
int main() {
  int prev;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    has[a[i]]++;
  }
  sort(a, a + n);
  for (int i = 0; i < n; i++) {
    if (has[a[i]] > 1) {
      has[a[i]]--;
      prev = a[i];
      a[i] = find_next(prev);
      cost += a[i] - prev;
      has[a[i]]++;
    }
  }
  cout << cost << endl;
  return 0;
}
