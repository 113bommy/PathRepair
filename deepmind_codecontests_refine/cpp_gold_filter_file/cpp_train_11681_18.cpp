#include <bits/stdc++.h>
using namespace std;
long long area[1005];
int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n;
  cin >> n;
  int i;
  for (i = 3; i <= n; i++) {
    cout << 1 << " " << 1 << " " << 2 << " " << i << endl;
    fflush(stdout);
    cin >> area[i];
  }
  vector<int> vl;
  vector<int> vr;
  for (i = 3; i <= n; i++) {
    cout << 2 << " " << 1 << " " << 2 << " " << i << endl;
    fflush(stdout);
    int s;
    cin >> s;
    if (s > 0) {
      vr.push_back(i);
    } else {
      vl.push_back(i);
    }
  }
  sort(vl.begin(), vl.end(), [](int i, int j) { return area[i] > area[j]; });
  sort(vr.begin(), vr.end(), [](int i, int j) { return area[i] > area[j]; });
  vector<int> ans;
  vector<int> tmpUp;
  vector<int> tmpDown;
  tmpUp.clear();
  tmpDown.clear();
  for (i = 1; i < vl.size(); i++) {
    cout << 2 << " " << 1 << " " << vl[0] << " " << vl[i] << endl;
    fflush(stdout);
    int s;
    cin >> s;
    if (s > 0) {
      tmpDown.push_back(vl[i]);
    } else {
      tmpUp.push_back(vl[i]);
    }
  }
  if (tmpUp.size() > 0) {
    sort(tmpUp.begin(), tmpUp.end(),
         [](int i, int j) { return area[i] < area[j]; });
    for (i = 0; i < tmpUp.size(); i++) ans.push_back(tmpUp[i]);
  }
  if (vl.size() > 0) ans.push_back(vl[0]);
  if (tmpDown.size() > 0) {
    sort(tmpDown.begin(), tmpDown.end(),
         [](int i, int j) { return area[i] > area[j]; });
    for (i = 0; i < tmpDown.size(); i++) ans.push_back(tmpDown[i]);
  }
  tmpUp.clear();
  tmpDown.clear();
  for (i = 1; i < vr.size(); i++) {
    cout << 2 << " " << 1 << " " << vr[0] << " " << vr[i] << endl;
    fflush(stdout);
    int s;
    cin >> s;
    if (s > 0) {
      tmpDown.push_back(vr[i]);
    } else {
      tmpUp.push_back(vr[i]);
    }
  }
  ans.push_back(2);
  if (tmpUp.size() > 0) {
    sort(tmpUp.begin(), tmpUp.end(),
         [](int i, int j) { return area[i] < area[j]; });
    for (i = 0; i < tmpUp.size(); i++) ans.push_back(tmpUp[i]);
  }
  if (vr.size() > 0) ans.push_back(vr[0]);
  if (tmpDown.size() > 0) {
    sort(tmpDown.begin(), tmpDown.end(),
         [](int i, int j) { return area[i] > area[j]; });
    for (i = 0; i < tmpDown.size(); i++) ans.push_back(tmpDown[i]);
  }
  cout << 0 << " " << 1 << " ";
  for (i = 0; i < ans.size(); i++) {
    cout << ans[i] << " ";
  }
  cout << endl;
  return 0;
}
