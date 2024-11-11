#include <bits/stdc++.h>
using namespace std;
int n;
int a[1000];
int diff(int x1, int x2) {
  int ans = 0;
  for (int i = 0; i < 4; i++) {
    ans += (x1 % 10) != (x2 % 10);
    x1 /= 10;
    x2 /= 10;
  }
  return ans;
}
void process(int ind, int pr) {
  for (int i = pr; i <= 9999; i++) {
    if (diff(i, a[ind]) <= 1) {
      a[ind] = i;
      return;
    }
  }
  cout << "No solution";
  exit(0);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    process(i, i == 0 ? 1000 : a[i - 1]);
  }
  for (int i = 0; i < n; i++) cout << a[i] << "\n";
  return 0;
}
