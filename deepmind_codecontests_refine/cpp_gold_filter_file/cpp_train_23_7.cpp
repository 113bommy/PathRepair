#include <bits/stdc++.h>
using namespace std;
int n, k;
int suma, sumb;
priority_queue<int> both, alice, bob;
int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    int t, a, b;
    cin >> t >> a >> b;
    if (a + b == 2) {
      both.push(-t);
    } else if (a == 1) {
      alice.push(-t);
    } else if (b == 1) {
      bob.push(-t);
    }
    suma += a;
    sumb += b;
  }
  if (suma < k || sumb < k) {
    cout << "-1\n";
    return 0;
  }
  long long ans = 0;
  int a = 0, b = 0;
  while (a < k || b < k) {
    long long C1 = 1e12, C2 = 1e12, C3 = 1e12;
    if (both.size()) {
      C1 = -both.top();
    }
    if (alice.size()) {
      C2 = -alice.top();
    }
    if (bob.size()) {
      C3 = -bob.top();
    }
    if ((C1 <= min(C2, C3) || C1 <= C2 + C3) && C1 != 1e12) {
      a++, b++;
      ans += C1;
      both.pop();
    } else {
      if (a < k && C2 != 1e12) {
        a++;
        ans += C2;
        alice.pop();
      }
      if (b < k && C3 != 1e12) {
        b++;
        ans += C3;
        bob.pop();
      }
    }
  }
  cout << ans << "\n";
  return 0;
}
