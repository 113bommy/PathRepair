#include <bits/stdc++.h>
using namespace std;
int main(int argc, const char* argv[]) {
  long long n, m;
  cin >> n >> m;
  long long mins = 0, maxs = 0;
  if (2 * m >= n) {
    mins = 0;
  } else {
    mins = n - 2 * m;
  }
  long long ans = 0, i = 1;
  while (ans < 2 * m) {
    ans = i * (i - 1);
    i++;
  }
  maxs = n - (i - 1);
  cout << mins << " " << maxs;
}
