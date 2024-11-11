#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, A;
  cin >> N;
  int ans = 1e9;
  while (cin >> A) {
    int cnt = 0;
    while (A % 2 == 0) A /= 2, cnt++;
    ans = min(ans, cnt);
  }
  cout << cnt << "\n";
}