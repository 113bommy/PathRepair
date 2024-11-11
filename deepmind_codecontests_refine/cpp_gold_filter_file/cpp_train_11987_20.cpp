#include <bits/stdc++.h>
using namespace std;
int m2[200010], a[200010], b[200010];
bool cmp(int a, int b) { return a > b; }
int main() {
  int n, c;
  cin >> n >> c;
  long long sum = 0;
  for (int j = (c - 1); j >= 1; j--) {
    sum += j * 2;
  }
  int c1 = 0;
  if (sum < n) {
    cout << "NO" << endl;
  } else {
    cout << "YES" << endl;
    for (int i = 1; i <= c; i++) {
      for (int j = i + 1; j <= c; j++) {
        cout << i << " " << j << endl;
        c1++;
        if (c1 == n) return 0;
        cout << j << " " << i << endl;
        c1++;
        if (c1 == n) return 0;
      }
    }
  }
}
