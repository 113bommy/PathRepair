#include <bits/stdc++.h>
using namespace std;
const int N = 100000 + 10;
int n, k;
int c0, c1;
int a[N];
int lst;
bool stopIt(int choose) {
  int l[2];
  l[0] = c0;
  l[1] = c1;
  for (int i = 0; i < n - k - 1; ++i) {
    int who = i & 1;
    if (who == lst) {
      if (l[1 - choose] > 1) {
        l[1 - choose]--;
      } else {
        l[choose]--;
      }
    } else {
      if (l[choose])
        l[choose]--;
      else
        l[1 - choose]--;
    }
  }
  if (l[0] && l[1]) return false;
  if (l[0]) l[0]--;
  if (l[1]) l[1]--;
  int lft = l[1] & 1;
  if (lst ^ lft) return false;
  return true;
}
void solve() {
  cin >> n >> k;
  int sum = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%d", a + i);
    a[i] &= 1;
    sum ^= a[i];
    if (a[i]) {
      c1++;
    } else {
      c0++;
    }
  }
  if (n == k) {
    if (sum) {
      puts("Stannis");
    } else {
      puts("Daenerys");
    }
    return;
  }
  if (c0 == 0 || c1 == 0) {
    int lft;
    if (c0 == 0) {
      lft = k & 1;
    } else {
      lft = 0;
    }
    if (lft) {
      puts("Stannis");
    } else {
      puts("Daenerys");
    }
    return;
  }
  if (n - k & 1) {
    lst = 0;
  } else {
    lst = 1;
  }
  int winner = lst;
  if (stopIt(0) || stopIt(1)) {
    winner = 1 - lst;
  }
  if (winner == 0) {
    puts("Stannis");
  } else {
    puts("Daenerys");
  }
}
int main() {
  solve();
  return 0;
}
