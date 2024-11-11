#include <bits/stdc++.h>
using namespace std;
int main(int argc, char **argv) {
  int n, a, b;
  cin >> n >> a >> b;
  std::vector<int> vh(n);
  for (int i = 0; i < n; i++) cin >> vh[i];
  sort(vh.begin(), vh.end());
  int x = vh[b] - vh[b - 1];
  if (x > 0)
    cout << x << endl;
  else
    cout << 0 << endl;
  return 0;
}
