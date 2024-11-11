#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a, b, ans;
  cin >> n >> a >> b;
  cout << n - max(a + 1, n - b) + 1;
}
