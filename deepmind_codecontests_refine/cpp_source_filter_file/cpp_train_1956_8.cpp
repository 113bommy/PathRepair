#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  n %= k;
  cout << min((k - n), n) << endl;
}
