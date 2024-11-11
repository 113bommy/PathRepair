#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int cnt = 0;
  int ans[n];
  int visited[100005] = {0};
  for (int i = 0; i < n; i++) {
    if (!visited[a[i]]) {
      cnt++;
      visited[a[i]] = 1;
    }
    ans[i] = cnt;
  }
  int v2[100005] = {0};
  long long sol = 0;
  for (int i = n - 1; i >= 0; i--) {
    if (!v2[a[i]]) {
      sol += ans[i - 1];
      v2[a[i]] = 1;
    }
  }
  cout << sol;
}
