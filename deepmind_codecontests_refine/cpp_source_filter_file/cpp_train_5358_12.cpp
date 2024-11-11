#include <bits/stdc++.h>
using namespace std;
const int inf = 2e9;
const int MOD = 1e9 + 7;
const int N = 0;
int a, b;
int main() {
  cin >> a >> b;
  for (int i = 1; i <= a; i++) printf("%d ", b + i);
  for (int i = b; i >= 1; i--) printf("%d ", i);
}
