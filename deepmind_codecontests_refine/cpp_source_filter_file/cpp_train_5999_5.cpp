#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  std::vector<int> onsight;
  int maxnum;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    onsight.push_back(a);
    maxnum = max(maxnum, a);
  }
  sort(onsight.begin(), onsight.end());
  int numDeclines(0);
  if (maxnum < 25) {
    cout << 0;
  } else {
    cout << maxnum - 25;
  }
  return 0;
}
