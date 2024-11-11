#include <bits/stdc++.h>
using namespace std;
vector<long long int> v1, v2, v, temp;
long long int dp[20][2][2][2][2][2][2], no1, no2, no3;
vector<long long int> ans1, ans2, ans3;
long long int solve(long long int pos, long long int n1t1, long long int n1t2,
                    long long int n2t1, long long int n2t2, long long int n3t1,
                    long long int n3t2) {
  if (pos == v2.size()) {
    long long int pw = 1, i;
    no1 = 0;
    no2 = 0;
    no3 = 0;
    for (i = ans1.size() - 1; i >= 0; i--) {
      no1 += pw * ans1[i];
      pw *= 2;
    }
    pw = 1;
    for (i = ans2.size() - 1; i >= 0; i--) {
      no2 += pw * ans2[i];
      pw *= 2;
    }
    pw = 1;
    for (i = ans3.size() - 1; i >= 0; i--) {
      no3 += pw * ans3[i];
      pw *= 2;
    }
    return 1;
  }
  long long int ans = dp[pos][n1t1][n1t2][n2t1][n2t2][n3t1][n3t2];
  if (ans != -1) return ans;
  ans = 0;
  long long int mini1, maxi1, mini2, maxi2, mini3, maxi3, nn1t1, nn1t2, nn2t1,
      nn2t2, nn3t1, nn3t2;
  if (!n1t1)
    mini1 = 0;
  else
    mini1 = v1[pos];
  if (!n2t1)
    mini2 = 0;
  else
    mini2 = v1[pos];
  if (!n3t1)
    mini3 = 0;
  else
    mini3 = v1[pos];
  if (!n1t2)
    maxi1 = 1;
  else
    maxi1 = v2[pos];
  if (!n2t2)
    maxi2 = 1;
  else
    maxi2 = v2[pos];
  if (!n3t2)
    maxi3 = 1;
  else
    maxi3 = v2[pos];
  for (long long int i = mini1; i <= maxi1; i++) {
    for (long long int j = mini2; j <= maxi2; j++) {
      for (long long int l = mini3; l <= maxi3; l++) {
        if (((i ^ j) ^ l) != 0) continue;
        if (!n1t1)
          nn1t1 = 0;
        else {
          if (i == v1[pos])
            nn1t1 = 1;
          else
            nn1t1 = 0;
        }
        if (!n1t2)
          nn1t2 = 0;
        else {
          if (i == v2[pos])
            nn1t2 = 1;
          else
            nn1t2 = 0;
        }
        if (!n2t1)
          nn2t1 = 0;
        else {
          if (j == v1[pos])
            nn2t1 = 1;
          else
            nn2t1 = 0;
        }
        if (!n2t2)
          nn2t2 = 0;
        else {
          if (j == v2[pos])
            nn2t2 = 1;
          else
            nn2t2 = 0;
        }
        if (!n3t1)
          nn3t1 = 0;
        else {
          if (l == v1[pos])
            nn3t1 = 1;
          else
            nn3t1 = 0;
        }
        if (!n3t2)
          nn3t2 = 0;
        else {
          if (l == v2[pos])
            nn3t2 = 1;
          else
            nn3t2 = 0;
        }
        ans1.push_back(i);
        ans2.push_back(j);
        ans3.push_back(l);
        ans = ans | solve(pos + 1, nn1t1, nn1t2, nn2t1, nn2t2, nn3t1, nn3t2);
        ans1.pop_back();
        ans2.pop_back();
        ans3.pop_back();
      }
    }
  }
  dp[pos][n1t1][n1t2][n2t1][n2t2][n3t1][n3t2] = ans;
  return ans;
}
void init() {
  long long int i, l1, l2, l3, l4, l5, l6;
  for (i = 0; i < 20; i++) {
    for (l1 = 0; l1 <= 1; l1++) {
      for (l2 = 0; l2 <= 1; l2++) {
        for (l3 = 0; l3 <= 1; l3++) {
          for (l4 = 0; l4 <= 1; l4++) {
            for (l5 = 0; l5 <= 1; l5++) {
              for (l6 = 0; l6 <= 1; l6++) dp[i][l1][l2][l3][l4][l5][l6] = -1;
            }
          }
        }
      }
    }
  }
}
int main() {
  long long int i, j, l, r, k, n, xr, st, tl, tr;
  cin >> l >> r >> k;
  if (r - l + 1 <= 6) {
    long long int ans = 100000000000000;
    n = r - l + 1;
    for (i = 0; i < (1 << n); i++) {
      xr = 0;
      st = 0;
      for (j = 0; j < n; j++) {
        if (i & (1 << j)) {
          xr = xr ^ (l + j);
          st++;
        }
      }
      if (xr < ans && st <= k && st > 0) {
        ans = xr;
        v.clear();
        for (j = 0; j < n; j++) {
          if (i & (1 << j)) v.push_back(j + l);
        }
      }
    }
    cout << ans << endl;
    cout << v.size() << endl;
    for (i = 0; i < v.size(); i++) cout << v[i] << " ";
    return 0;
  }
  if (k == 1) {
    cout << l << endl;
    cout << "1" << endl;
    cout << l;
    return 0;
  }
  if (k == 2) {
    cout << "1" << endl;
    if (l % 2) l++;
    cout << "2" << endl;
    cout << l << " " << l + 1 << endl;
    return 0;
  }
  if (k >= 4) {
    for (i = l;; i++) {
      if (i % 4 == 0) break;
    }
    cout << "0" << endl;
    cout << "4" << endl;
    cout << i << " " << i + 1 << " " << i + 2 << " " << i + 3 << endl;
    return 0;
  }
  tl = l;
  tr = r;
  while (tl > 0) {
    temp.push_back(tl % 2);
    tl /= 2;
  }
  while (tr > 0) {
    v2.push_back(tr % 2);
    tr /= 2;
  }
  reverse(temp.begin(), temp.end());
  for (i = 1; i <= v2.size() - temp.size(); i++) v1.push_back(0);
  for (i = 0; i < temp.size(); i++) v1.push_back(temp[i]);
  reverse(v2.begin(), v2.end());
  init();
  long long int ans = solve(0, 1, 1, 1, 1, 1, 1);
  if (ans) {
    cout << "0" << endl;
    cout << "3" << endl;
    cout << no1 << " " << no2 << " " << no3 << endl;
    return 0;
  } else {
    cout << "1" << endl;
    cout << "2" << endl;
    if (l % 2) l++;
    cout << l << " " << l + 1 << endl;
    return 0;
  }
  return 0;
}
