#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[n];
  int pos[n + 1];
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    pos[a[i]] = i;
  }
  int mx = 1;
  int count = 0;
  for (int i = 2; i <= n; i++) {
    while (i <= n && pos[i] > pos[i - 1]) {
      count++;
      i++;
    }
    mx = max(mx, count + 1);
    count = 0;
  }
  cout << n - mx << endl;
}
