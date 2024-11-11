#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, k;
  cin >> n >> k;
  cout << ((n / k) & 1 ? "YES" : "NO");
}
