#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, t;
  cin >> n >> k >> t;
  cout << (k >= t ? t : (n >= t ? k : k - (t - n)));
}
