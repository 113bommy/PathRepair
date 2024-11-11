#include <bits/stdc++.h>
using namespace std;
const int nn = 100005;
long long aa[nn][3];
void merg(int l, int mid, int r) {
  int sz1 = mid - l + 1;
  int sz2 = r - mid;
  long long lef[sz1][3];
  long long rit[sz2][3];
  for (int i = l; i < mid + 1; i++) {
    lef[i - l][0] = aa[i][0];
    lef[i - l][1] = aa[i][1];
    lef[i - l][2] = aa[i][2];
  }
  for (int i = mid + 1; i < r + 1; i++) {
    rit[i - mid - 1][0] = aa[i][0];
    rit[i - mid - 1][1] = aa[i][1];
    rit[i - mid - 1][2] = aa[i][2];
  }
  int ptr1 = 0, ptr2 = 0;
  int cnt = l;
  while (ptr1 < sz1 && ptr2 < sz2) {
    if (lef[ptr1][0] > rit[ptr2][0]) {
      lef[ptr1][2] = max(lef[ptr1][2], rit[ptr2][1]);
      aa[cnt][0] = rit[ptr2][0];
      aa[cnt][1] = rit[ptr2][1];
      aa[cnt][2] = rit[ptr2][2];
      ptr2++;
    } else {
      long long val = ptr1 > 0 ? lef[ptr1 - 1][2] : -1;
      lef[ptr1][2] = max(lef[ptr1][2], val);
      aa[cnt][0] = lef[ptr1][0];
      aa[cnt][1] = lef[ptr1][1];
      aa[cnt][2] = lef[ptr1][2];
      ptr1++;
    }
    cnt++;
  }
  while (ptr1 < sz1) {
    long long val = ptr1 > 0 ? lef[ptr1 - 1][2] : -1;
    lef[ptr1][2] = max(lef[ptr1][2], val);
    aa[cnt][0] = lef[ptr1][0];
    aa[cnt][1] = lef[ptr1][1];
    aa[cnt][2] = lef[ptr1][2];
    ptr1++;
    cnt++;
  }
  while (ptr2 < sz2) {
    aa[cnt][0] = rit[ptr2][0];
    aa[cnt][1] = rit[ptr2][1];
    aa[cnt][2] = rit[ptr2][2];
    ptr2++;
    cnt++;
  }
}
void divi(int l, int r) {
  int mid = (l + r) / 2;
  if (l < r) {
    divi(l, mid);
    divi(mid + 1, r);
    merg(l, mid, r);
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> aa[i][0];
    aa[i][1] = i;
    aa[i][2] = -1;
  }
  vector<pair<int, int>> vv;
  divi(0, n - 1);
  for (int i = 0; i < n; i++) {
    int ii = aa[i][1];
    int bb;
    if (aa[i][2] != -1) {
      bb = aa[i][2] - aa[i][1];
      bb--;
    } else
      bb = -1;
    vv.push_back(make_pair(ii, bb));
  }
  sort(vv.begin(), vv.end());
  for (auto x : vv) cout << max(-1, x.second) << " ";
  return 0;
}
