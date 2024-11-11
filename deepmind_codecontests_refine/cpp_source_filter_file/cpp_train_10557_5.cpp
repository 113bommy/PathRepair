#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++)
    if (i < k)
      cout << i * 2 + 2 << " " << i * 2 + 1 << " ";
    else
      cout << 2 * i + 1 << " " << 2 * i + 2;
}
