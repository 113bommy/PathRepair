#include <bits/stdc++.h>
using namespace std;
int n;
void check(int x) {
  int mps[100005], k = 0;
  while (x != 0) {
    mps[++k] = x % n;
    x /= n;
  }
  for (int i = k; i >= 1; i--) {
    cout << mps[i];
  }
  cout << " ";
}
int main() {
  cin >> n;
  for (int i = 1; i <= n - 1; i++) {
    for (int j = 1; j <= n - 1; j++) {
      check(i * j);
    }
    cout << endl;
  }
}
