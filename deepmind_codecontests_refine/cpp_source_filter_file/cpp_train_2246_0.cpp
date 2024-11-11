#include <bits/stdc++.h>
using namespace std;
vector<long long> N;
vector<long long> N1;
vector<long long> AN;
int main() {
  long long x, y;
  cin >> x >> y;
  long long ans1 = 0, ans2, x1 = 0, y1 = 0;
  ans1 = x + y;
  while (ans1 > 0) {
    AN.push_back(ans1 % 10);
    ans1 /= 10;
  }
  while (x > 0) {
    N.push_back(x % 10);
    x /= 10;
  }
  while (y > 0) {
    N1.push_back(y % 10);
    y /= 10;
  }
  reverse(N.begin(), N.end());
  reverse(N1.begin(), N1.end());
  reverse(AN.begin(), AN.end());
  for (int i = 0; i <= AN.size(); i++) {
    if (AN[i] != 0) {
      ans1 += AN[i];
      ans1 *= 10;
    }
  }
  for (int i = 0; i < N.size(); i++) {
    if (N[i] == 0)
      continue;
    else {
      x1 += N[i];
      x1 *= 10;
    }
  }
  for (int i = 0; i <= N1.size(); i++) {
    if (N1[i] != 0) {
      y1 += N1[i];
      y1 *= 10;
    }
  }
  x1 /= 10;
  y1 /= 10;
  ans1 /= 10;
  ans2 = x1 + y1;
  if (ans1 == ans2) {
    cout << "YES";
    return 0;
  }
  cout << "NO";
}
