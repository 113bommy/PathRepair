#include <bits/stdc++.h>
using namespace std;
int Array[1000005];
int main() {
  ios ::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n;
  cin >> n;
  cout << 2 * (n / 3) + (n % 3 != 0);
}
