#include <bits/stdc++.h>
#pragma warning(disable : 4996)
using namespace std;
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
void solution(int t) {
  int n, r;
  cin >> n >> r;
  int previous_pos = -r + 1;
  int possible_new_pos = -1;
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    if (x == 0) continue;
    if (i - previous_pos <= 2 * r - 1) {
      possible_new_pos = i;
    } else {
      if (possible_new_pos == -1 || i - possible_new_pos > 2 * r - 1) {
        cout << -1;
        return;
      }
      ans++;
      previous_pos = possible_new_pos;
      possible_new_pos = i;
    }
  }
  int i = n + r;
  if (i - previous_pos <= 2 * r - 1) {
    possible_new_pos = i;
  } else {
    if (possible_new_pos == -1 || i - possible_new_pos > 2 * r - 1) {
      cout << -1;
      return;
    }
    ans++;
    previous_pos = possible_new_pos;
    possible_new_pos = i;
  }
  cout << ans;
}
int main() {
  int t = 1;
  for (int i = 0; i < t; i++) solution(i);
  return 0;
}
