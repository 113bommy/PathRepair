#include <bits/stdc++.h>
using namespace std;
int main() {
  int v1, v2, v3, v;
  cin >> v1 >> v2 >> v3 >> v;
  for (int i = 250; i >= 1; --i)
    for (int j = i - 1; j >= 1; --j)
      for (int k = j - 1; k >= 1; --k)
        if (v1 <= i && 2 * v1 >= i && v2 <= j && 2 * v2 >= j && v3 <= k &&
            2 * v3 >= k && v <= k && 2 * v >= k && 2 * v < j && 2 * v < i)
          return cout << i << " " << j << " " << k << endl, 0;
  cout << -1 << endl;
}
