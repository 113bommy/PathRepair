#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  long ans = 0;
  for (int i = 1; i <= N; i++) if (i % 3 && i % 5) ans += i;
  cout << ans << "\n";
}