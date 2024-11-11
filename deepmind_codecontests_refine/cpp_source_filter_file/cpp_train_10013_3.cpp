#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int b, g, n;
  cin >> b >> g >> n;
  int answer = 0;
  for (int i = 0; i <= b; i++) {
    if (i + g >= n) answer++;
  }
  cout << answer;
  return 0;
}
