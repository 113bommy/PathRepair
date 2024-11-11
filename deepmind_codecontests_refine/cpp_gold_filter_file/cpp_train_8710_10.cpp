#include <bits/stdc++.h>
using namespace std;
const int N = 5 * 1e5 + 1;
int ans[6];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  map<string, int> a = {{"purple", 0}, {"green", 1}, {"blue", 2},
                        {"orange", 3}, {"red", 4},   {"yellow", 5}};
  map<int, string> b = {{0, "Power"}, {1, "Time"},    {2, "Space"},
                        {3, "Soul"},  {4, "Reality"}, {5, "Mind"}};
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    ans[a[s]] = 1;
  }
  cout << 6 - n << "\n";
  for (int i = 0; i < 6; i++) {
    if (!ans[i]) {
      cout << b[i] << "\n";
    }
  }
}
