#include <bits/stdc++.h>
using namespace std;
const int M = 1000000007, BIG = 0x3f3f3f3f;
int n;
vector<int> a;
vector<int> Process() {
  vector<int> ans = {0};
  int x = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] < 0 && ++x > 2) {
      x = 1;
      ans.push_back(0);
    }
    ans.back()++;
  }
  return ans;
}
void Output() {
  const vector<int> ans = Process();
  cout << ans.size() << "\n";
  for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
  cout << "\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  while (cin >> n) {
    a.resize(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    Output();
  }
  return 0;
}
