#include <bits/stdc++.h>
using namespace std;
string inp;
vector<char> diff;
vector<int> cnt;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> inp;
  diff.push_back(inp[0]);
  cnt.push_back(1);
  for (int i = 1; i < inp.size(); i++) {
    if (inp[i] != inp[i - 1]) {
      diff.push_back(inp[i]);
      cnt.push_back(1);
    } else
      (*cnt.rbegin())++;
  }
  if (diff.size() % 2 == 0) {
    cout << 0 << endl;
    return 0;
  }
  for (int i = 0; i < diff.size() / 2; i++) {
    if (diff[i] != diff[diff.size() - 1 - i]) {
      cout << 0 << endl;
      return 0;
    }
    if (cnt[i] + cnt[diff.size() / 2 - 1 - i] < 3) {
      cout << 0 << endl;
      return 0;
    }
  }
  if (cnt[diff.size() / 2] >= 2)
    cout << cnt[diff.size() / 2] + 1 << endl;
  else
    cout << 0 << endl;
  return 0;
}
