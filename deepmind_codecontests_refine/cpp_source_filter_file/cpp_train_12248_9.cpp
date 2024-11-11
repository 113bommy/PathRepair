#include <bits/stdc++.h>
using namespace std;
const int infint = INT_MAX;
const long long infll = LLONG_MAX;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n, a, b;
  cin >> n >> a >> b;
  long long takeA = 0, takeB = 0;
  for (int i = 0; i < n + 1; i++) {
    long long tA = 1LL * i * a;
    long long tB = n - tA;
    if (tB % b != 0 || tB < 0) continue;
    takeA = i;
    takeB = tB / b;
    break;
  }
  if (takeA == 0 && takeB == 0) {
    cout << -1;
    return 0;
  }
  vector<int> ans;
  for (int i = 0; i < takeA; i++) {
    int start = i * a;
    vector<int> fict;
    for (int j = 0; j < a; j++) fict.push_back(start + (j + a - 1) % a);
    for (int j = 0; j < fict.size(); j++) ans.push_back(fict[j]);
  }
  for (int i = 0; i < takeB; i++) {
    int start = a * a + b * i;
    vector<int> fict;
    for (int j = 0; j < b; j++) fict.push_back(start + (j + b - 1) % b);
    for (int j = 0; j < fict.size(); j++) ans.push_back(fict[j]);
  }
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] + 1 << " ";
  }
  return 0;
}
