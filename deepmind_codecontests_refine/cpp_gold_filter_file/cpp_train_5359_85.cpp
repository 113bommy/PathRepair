#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
  while (b != 0) {
    int r = a % b;
    a = b;
    b = r;
  }
  return a;
}
int main(int argc, char *argv[]) {
  int n, m;
  cin >> n >> m;
  int happyBoys, happyGirls;
  vector<bool> isHappyBoy(n, false);
  vector<bool> isHappyGirl(m, false);
  cin >> happyBoys;
  for (int i = 0; i < happyBoys; ++i) {
    int x;
    cin >> x;
    isHappyBoy[x] = true;
  }
  cin >> happyGirls;
  for (int i = 0; i < happyGirls; ++i) {
    int x;
    cin >> x;
    isHappyGirl[x] = true;
  }
  int lcm = (n * m) / gcd(n, m);
  for (int i = 0; i < 2 * n * m; i++) {
    int x = i % n;
    int y = i % m;
    if (isHappyBoy[x] || isHappyGirl[y]) {
      isHappyBoy[x] = isHappyGirl[y] = true;
    }
  }
  for (int i = 0; i < n; i++) {
    if (!isHappyBoy[i]) {
      cout << "No";
      return 0;
    }
  }
  for (int i = 0; i < m; i++) {
    if (!isHappyGirl[i]) {
      cout << "No";
      return 0;
    }
  }
  cout << "Yes";
  return 0;
}
