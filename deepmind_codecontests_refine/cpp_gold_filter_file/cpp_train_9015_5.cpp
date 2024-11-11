#include <bits/stdc++.h>
using namespace std;
int n, sum;
char a[200200];
bool used[200200];
vector<int> remd;
vector<int> nonzero;
int getRand() { return rand() << 15 + rand(); }
int calc(int x, int y) {
  int ans = sum, curr = 0;
  for (int i = x; i < x + y + 1; ++i) {
    curr *= 10;
    curr += (a[i] - '0');
    ans -= (a[i] - '0');
  }
  return ans + curr;
}
int check(int num) {
  int ans1 = 0, ans2 = 0;
  while (num > 0) {
    ans1 += num % 10;
    num /= 10;
  }
  while (ans1 > 0) {
    ans2 += ans1 % 10;
    ans1 /= 10;
  }
  return ans2;
}
int printP(int ans) {
  vector<int> v;
  while (ans > 0) {
    v.push_back(ans % 10);
    ans /= 10;
  }
  int ans2 = 0;
  for (int i = v.size() - 1; i >= 0; --i) {
    cout << v[i];
    ans2 += v[i];
    if (i) {
      cout << "+";
    }
  }
  cout << "\n";
  return ans2;
}
int rem(int ans, int pos) {
  if (used[pos] || (pos > 0 && used[pos - 1]) || used[pos + 1]) {
    return ans;
  }
  used[pos] = 1;
  remd.push_back(pos);
  return ans + (a[pos] - '0') * 9;
}
int reset() {
  while (remd.size()) {
    used[remd.back()] = 0;
    remd.pop_back();
  }
  return sum;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  srand(42);
  cin >> n;
  cin >> a;
  for (int i = 0; i < n; ++i) {
    sum += a[i] - '0';
    if (a[i] != '0' && i != n - 1) {
      nonzero.push_back(i);
    }
  }
  int m10 = 1;
  while (m10 < sum) {
    m10 *= 10;
  }
  int ans = sum, x = 0, y = 0;
  while (check(ans) >= 10) {
    if (ans > m10) {
      ans = reset();
    } else {
      ans = rem(ans, nonzero[getRand() % nonzero.size()]);
    }
  }
  for (int i = 0; i < n; ++i) {
    cout << a[i];
    if (!(used[i] || i == n - 1)) {
      cout << "+";
    }
  }
  cout << "\n";
  ans = printP(ans);
  printP(ans);
  return 0;
}
