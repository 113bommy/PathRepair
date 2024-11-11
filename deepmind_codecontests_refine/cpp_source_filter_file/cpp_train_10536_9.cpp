#include <bits/stdc++.h>
using namespace std;
int mul(long long a, long long b) { return (a * b) % 1000000007; }
int add(int a, int b) {
  int ans = a + b;
  if (ans >= 1000000007) {
    return ans - 1000000007;
  }
  return ans;
}
long long power(long long x, long long p) {
  if (!p) return 1;
  long long z = power(x, p / 2);
  z *= z;
  z %= 1000000007;
  if (p % 2 == 0) return z;
  z *= x;
  z %= 1000000007;
  return z;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int t;
  cin >> t;
  while (t--) {
    int up, down, right, left, i;
    up = down = right = left = 0;
    string s;
    cin >> s;
    for (i = 0; i < s.size(); i++) {
      if (s[i] == 'U')
        up++;
      else if (s[i] == 'D')
        down++;
      else if (s[i] == 'L')
        left++;
      else
        right++;
    }
    if ((up == 0 || down == 0) && (right == 0 || left == 0)) {
      cout << 0 << "\n";
    } else if ((right >= 1 && left >= 1) && (up == 0 || down == 0)) {
      cout << 2 << "\n";
      cout << "RL"
           << "\n";
    } else if ((up >= 1 && down >= 1) && (right == 0 || left == 0)) {
      cout << 2 << "\n";
      cout << "UP"
           << "\n";
    } else {
      down = min(up, down);
      up = min(up, down);
      right = min(right, left);
      left = min(right, left);
      cout << down + up + right + left << "\n";
      for (i = 1; i <= up; i++) {
        cout << 'U';
      }
      for (i = 1; i <= right; i++) {
        cout << 'R';
      }
      for (i = 1; i <= down; i++) {
        cout << 'D';
      }
      for (i = 1; i <= left; i++) {
        cout << 'L';
      }
      if (down + up + right + left != 0) cout << "\n";
    }
  }
}
