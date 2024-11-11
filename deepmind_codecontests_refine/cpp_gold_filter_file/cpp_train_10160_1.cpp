#include <bits/stdc++.h>
using namespace std;
vector<long long> crops;
int main() {
  cin.tie(0);
  cin.sync_with_stdio(0);
  int n, m, k, t, x, y;
  cin >> n >> m >> k >> t;
  while (k--) {
    cin >> x >> y;
    x--;
    crops.push_back(x * m + y);
  }
  sort(crops.begin(), crops.end());
  while (t--) {
    k = 0;
    int w = 0;
    cin >> x >> y;
    --x;
    int pos = x * m + y;
    for (auto it : crops) {
      if (it < pos)
        k++;
      else if (it == pos)
        w = 1;
      else
        break;
    }
    pos -= k;
    pos %= 3;
    if (w)
      cout << "Waste\n";
    else if (pos == 1)
      cout << "Carrots\n";
    else if (pos == 2)
      cout << "Kiwis\n";
    else
      cout << "Grapes\n";
  }
  return 0;
}
