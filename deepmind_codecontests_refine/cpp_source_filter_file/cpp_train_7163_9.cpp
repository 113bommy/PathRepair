#include <bits/stdc++.h>
using namespace std;
int n, a, b;
int main() {
  cin >> n >> a >> b;
  cout << max(a, b) << " " << max(0, a + b - n);
}
