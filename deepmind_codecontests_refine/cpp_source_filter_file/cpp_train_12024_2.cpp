#include <bits/stdc++.h>
using namespace std;
int n, ns[1000005];
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    int a;
    scanf("%d", &a);
    ns[a] = 1;
  }
  int ans = 0;
  for (int i = 0; i < 1000005; i++)
    if (ns[i])
      for (int j = i + i; j < 1000005; j += i)
        if (ns[j]) ns[j] = max(ns[j], ns[i] + 1), ans = max(ans, ns[j]);
  cout << ans << endl;
  return 0;
}
