#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, k;
  cin >> n >> k;
  cout << k / n + !!(k % n) << '\n';
}
