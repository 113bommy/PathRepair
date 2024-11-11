#include <bits/stdc++.h>
using namespace std;
int w, h, k, a;
int main() {
  cin >> w >> h >> k;
  cout << k * (2 * w + 2 * h - 8 * k + 4);
}
