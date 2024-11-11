#include <bits/stdc++.h>
using namespace std;
vector<int> a, b;
int n;
int f(int i, int j, int who) {
  if (i == n && j == n) {
    return 0;
  }
  if (who == 0) {
    if (i == n) {
      return f(i, j + 1, 1 - who);
    } else if (j == n) {
      return a[i] + f(i + 1, j, 1 - who);
    } else {
      return max(a[i] + f(i + 1, j, 1 - who), f(i, j + 1, 1 - who));
    }
  }
  if (who == 1) {
    if (j == n) {
      return f(i + 1, j, 1 - who);
    } else if (i == n) {
      return f(i, j + 1, 1 - who) - b[j];
    } else {
      return min(f(i, j + 1, 1 - who) - b[j], f(i + 1, j, 1 - who));
    }
  }
}
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    int u;
    cin >> u;
    a.push_back(u);
  }
  for (int i = 0; i < n; i++) {
    int u;
    cin >> u;
    b.push_back(u);
  }
  sort(a.begin(), a.end(), greater<int>());
  sort(b.begin(), b.end(), greater<int>());
  long long ans = 0;
  int who = 0;
  int i, j;
  i = j = 0;
  for (int k = 0; k < 2 * n; k++) {
    if (who == 0) {
      if (i == n) {
        j++;
      } else if (j == n) {
        ans += a[i];
        i++;
      } else {
        if (a[i] >= b[j]) {
          ans += a[i];
          i++;
        } else {
          j++;
        }
      }
    }
    if (who == 1) {
      if (j == n) {
        i++;
      } else if (i == n) {
        ans -= b[j];
        j++;
      } else {
        if (a[i] <= b[j]) {
          ans -= b[j];
          j++;
        } else {
          i++;
        }
      }
    }
    who = 1 - who;
  }
  cout << ans << '\n';
}
