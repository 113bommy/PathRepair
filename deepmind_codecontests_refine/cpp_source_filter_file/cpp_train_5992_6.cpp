#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1);
const double EPS = 1e-7;
const int inf = 1e8;
int main() {
  int n, sum = 0;
  cin >> n;
  vector<int> in(n);
  for (int i = 0; i < n; i++) cin >> in[i];
  for (int i = 0; i < n; i++) sum += in[i];
  vector<int> used(n);
  for (int i = 0; i < n; i++)
    if (!used[i]) {
      for (int j = i + 1; j < n; j++)
        if (!used[i] && in[i] + in[j] == sum * 2 / n) {
          used[i] = used[j] = true;
          cout << i + 1 << " " << j + 1 << endl;
          break;
        }
    }
}
