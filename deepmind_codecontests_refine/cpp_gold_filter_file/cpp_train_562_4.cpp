#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long a, b;
  cin >> a >> b;
  if (a == 0) {
    cout << -b * b << "\n";
    for (int i = 0; i < b; i++) cout << "x";
    return 0;
  } else if (b == 0) {
    cout << a * a << "\n";
    for (int i = 0; i < a; i++) cout << "o";
    return 0;
  }
  long long ans = -1e18, id = -1;
  for (long long i = 1; i <= b; i++) {
    long long cnt = b % i, cur = 0;
    cur -= cnt * ((b + i - 1) / i) * ((b + i - 1) / i);
    cur -= (i - cnt) * (b / i) * (b / i);
    if (a < i - 1) continue;
    if (i == 1) {
      cur += a * a;
    } else {
      cur += i - 2;
      cur += (a - i + 2) * (a - i + 2);
    }
    if (ans <= cur) ans = cur, id = i;
  }
  cout << ans << "\n";
  if (id == 1) {
    for (int i = 0; i < b; i++) cout << "x";
    for (int i = 0; i < a; i++) cout << "o";
    cout << "\n";
    return 0;
  }
  long long cnt = b % id, c = a;
  for (int i = 0; i < cnt; i++) {
    for (int j = 0; j < (b + id - 1) / id; j++) cout << "x";
    if (i < id - 2) {
      cout << "o";
      c--;
    }
    if (i == id - 2) {
      for (int i = 0; i < c; i++) cout << "o";
    }
  }
  for (int i = cnt; i < id; i++) {
    for (int j = 0; j < b / id; j++) cout << "x";
    if (i < id - 2) {
      cout << "o";
      c--;
    }
    if (i == id - 2) {
      for (int i = 0; i < c; i++) cout << "o";
    }
  }
  cout << "\n";
}
