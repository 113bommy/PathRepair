#include <bits/stdc++.h>
using namespace std;
long long mypow(long long a, long long b) {
  if (b == 0) return 1;
  long long temp = mypow(a, b / 2);
  temp = (temp * temp) % 1000000007LL;
  if (b % 2 == 1) temp = (a * temp) % 1000000007LL;
  return temp;
}
int mygcd(int a, int b) {
  if (b == 0) return a;
  return mygcd(b, a % b);
}
int cntBits(long long a) {
  int ret = 0;
  while (a > 0) {
    ret++;
    a /= 2;
  }
  return ret;
}
int points[200002][5], mxSeg[32][4 * 200002], mnSeg[32][4 * 200002];
vector<vector<int> > coeff;
vector<int> temp;
void build_coeff(int index, int k) {
  if (index == k)
    coeff.push_back(temp);
  else {
    temp.push_back(1);
    build_coeff(index + 1, k);
    temp.pop_back();
    temp.push_back(-1);
    build_coeff(index + 1, k);
    temp.pop_back();
  }
}
int getSum(int point_index, int coeff_index) {
  int ret = 0;
  for (int i = 0; i < coeff[coeff_index].size(); i++) {
    ret += coeff[coeff_index][i] * points[point_index][i];
  }
  return ret;
}
void buildSeg1(int l, int r, int coeff, int index) {
  if (l == r)
    mxSeg[coeff][index] = getSum(l, coeff);
  else {
    int mid = l + (r - l) / 2;
    buildSeg1(l, mid, coeff, 2 * index + 1);
    buildSeg1(mid + 1, r, coeff, 2 * index + 2);
    mxSeg[coeff][index] =
        max(mxSeg[coeff][2 * index + 1], mxSeg[coeff][2 * index + 2]);
  }
}
void buildSeg2(int l, int r, int coeff, int index) {
  if (l == r)
    mnSeg[coeff][index] = getSum(l, coeff);
  else {
    int mid = l + (r - l) / 2;
    buildSeg2(l, mid, coeff, 2 * index + 1);
    buildSeg2(mid + 1, r, coeff, 2 * index + 2);
    mnSeg[coeff][index] =
        min(mnSeg[coeff][2 * index + 1], mnSeg[coeff][2 * index + 2]);
  }
}
void updateSeg1(int req_index, int l, int r, int coeff, int index) {
  if (l == r && l == req_index)
    mxSeg[coeff][index] = getSum(l, coeff);
  else {
    int mid = l + (r - l) / 2;
    if (req_index <= mid)
      updateSeg1(req_index, l, mid, coeff, 2 * index + 1);
    else
      updateSeg1(req_index, mid + 1, r, coeff, 2 * index + 2);
    mxSeg[coeff][index] =
        max(mxSeg[coeff][2 * index + 1], mxSeg[coeff][2 * index + 2]);
  }
}
void updateSeg2(int req_index, int l, int r, int coeff, int index) {
  if (l == r && l == req_index)
    mnSeg[coeff][index] = getSum(l, coeff);
  else {
    int mid = l + (r - l) / 2;
    if (req_index <= mid)
      updateSeg2(req_index, l, mid, coeff, 2 * index + 1);
    else
      updateSeg2(req_index, mid + 1, r, coeff, 2 * index + 2);
    mnSeg[coeff][index] =
        min(mnSeg[coeff][2 * index + 1], mnSeg[coeff][2 * index + 2]);
  }
}
int querySeg1(int req_l, int req_r, int l, int r, int index, int coeff) {
  if (req_r < l || r < req_l) return INT_MIN;
  if (l >= req_l && r <= req_r) return mxSeg[coeff][index];
  int mid = l + (r - l) / 2, lef, rig;
  lef = querySeg1(req_l, req_r, l, mid, 2 * index + 1, coeff);
  rig = querySeg1(req_l, req_r, mid + 1, r, 2 * index + 2, coeff);
  return max(lef, rig);
}
int querySeg2(int req_l, int req_r, int l, int r, int index, int coeff) {
  if (req_r < l || r < req_l) return INT_MAX;
  if (l >= req_l && r <= req_r) return mnSeg[coeff][index];
  int mid = l + (r - l) / 2, lef, rig;
  lef = querySeg2(req_l, req_r, l, mid, 2 * index + 1, coeff);
  rig = querySeg2(req_l, req_r, mid + 1, r, 2 * index + 2, coeff);
  return min(lef, rig);
}
int main() {
  ios::sync_with_stdio(0);
  int tt = 1;
  for (int tcase = 1; tcase <= tt; tcase++) {
    int n, k;
    cin >> n >> k;
    temp.push_back(1);
    build_coeff(1, k);
    int tot_coeffs = (1 << (k - 1));
    for (int i = 0; i < n; i++)
      for (int j = 0; j < k; j++) cin >> points[i][j];
    for (int i = 0; i < tot_coeffs; i++) {
      buildSeg1(0, n - 1, i, 0);
      buildSeg2(0, n - 1, i, 0);
    }
    int q;
    cin >> q;
    while (q--) {
      int type;
      cin >> type;
      if (type == 1) {
        int i;
        cin >> i;
        i--;
        for (int j = 0; j < k; j++) cin >> points[i][j];
        for (int j = 0; j < tot_coeffs; j++) {
          updateSeg1(i, 0, n - 1, j, 0);
          updateSeg2(i, 0, n - 1, j, 0);
        }
      } else {
        int l, r, ans = 0;
        cin >> l >> r;
        l--;
        r--;
        for (int i = 0; i < tot_coeffs; i++) {
          ans = max(ans, abs(querySeg1(l, r, 0, n - 1, 0, i) -
                             querySeg2(l, r, 0, n - 1, 0, i)));
        }
        cout << ans << "\n";
      }
    }
  }
  return 0;
}
