#include <bits/stdc++.h>
using namespace std;
const int N = 200004;
int n, a[N];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  for (int i = 2; i < n; i++) {
    if (a[i] <= a[i - 1] && a[i] <= a[i + 1]) {
      cout << "NO";
      return 0;
    }
  }
  cout << "YES" << endl;
}
