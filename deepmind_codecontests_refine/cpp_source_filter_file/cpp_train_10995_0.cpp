#include <bits/stdc++.h>
using namespace std;
pair<long long int, long long int> arr[3005], table[3005][25];
long long int ans[3005], brr[3005], val1, val2, val3, ans1, ans2, ans3, n, ind1,
    ind2, ind3, temp_ind1, temp_ind2, temp_ind3;
inline long long int ceiling(long long int x, long long int y) {
  return (x + y - 1) / y;
}
void build() {
  for (long long int i = 1; i <= n; i++) table[i][0] = make_pair(brr[i], i);
  for (long long int j = 1; j <= 20; j++) {
    for (long long int i = 1; i <= n - (1 << j) + 1; i++)
      table[i][j] = max(table[i][j - 1], table[i + (1 << (j - 1))][j - 1]);
  }
}
inline pair<long long int, long long int> query(long long int l,
                                                long long int r) {
  long long int len = r - l + 1;
  long long int k = log2(len);
  return max(table[l][k], table[r + 1 - (1 << k)][k]);
}
void update_ans() {
  if (val1 > ans1) {
    ans1 = val1;
    ind1 = temp_ind1;
    ans2 = val2;
    ind2 = temp_ind2;
    ans3 = val3;
    ind3 = temp_ind3;
  } else if (val1 == ans1 && val2 > ans2) {
    ans1 = val1;
    ind1 = temp_ind1;
    ans2 = val2;
    ind2 = temp_ind2;
    ans3 = val3;
    ind3 = temp_ind3;
  } else if (val1 == ans1 && val2 == ans2 && val3 > ans3) {
    ans1 = val1;
    ind1 = temp_ind1;
    ans2 = val2;
    ind2 = temp_ind2;
    ans3 = val3;
    ind3 = temp_ind3;
  }
}
int main() {
  ios::sync_with_stdio(false);
  ;
  cin.tie(0);
  ;
  long long int i, j, x, y, l, r, sz1, sz2, sz3;
  cin >> n;
  for (i = 1; i <= n; i++) {
    cin >> arr[i].first;
    arr[i].second = i;
  }
  sort(arr + 1, arr + n + 1);
  reverse(arr + 1, arr + n + 1);
  for (i = 1; i <= n; i++) brr[i] = arr[i].first - arr[i + 1].first;
  build();
  for (i = 1; i < n; i++) {
    for (j = i + 1; j < n; j++) {
      val1 = arr[i].first - arr[i + 1].first;
      val2 = arr[j].first - arr[j + 1].first;
      sz1 = i;
      sz2 = j - i;
      temp_ind1 = i;
      temp_ind2 = j;
      if (sz1 <= sz2) {
        l = j + sz1;
        r = min(n, j + 2 * sz1);
        if (l <= r) {
          auto temp = query(l, r);
          val3 = temp.first;
          sz3 = temp.second - j;
          temp_ind3 = temp.second;
          if (sz1 <= sz3) {
            if (sz1 > 0 && sz2 > 0 && sz3 > 0 && sz2 <= 2 * sz1 &&
                sz3 <= 2 * sz1)
              update_ans();
          }
        }
      }
      if (sz2 <= sz1) {
        l = j + sz2;
        r = min(n, j + 2 * sz2);
        if (l <= r) {
          auto temp = query(l, r);
          val3 = temp.first;
          sz3 = temp.second - j;
          temp_ind3 = temp.second;
          if (sz2 <= sz3) {
            if (sz1 > 0 && sz2 > 0 && sz3 > 0 && sz1 <= 2 * sz2 &&
                sz3 <= 2 * sz2)
              update_ans();
          }
        }
      }
      l = j + ceiling(max(sz1, sz2), 2);
      r = j + min(sz1, sz2);
      if (l <= r) {
        auto temp = query(l, r);
        val3 = temp.first;
        sz3 = temp.second - j;
        temp_ind3 = temp.second;
        if (sz1 > 0 && sz2 > 0 && sz3 > 0 && sz3 <= sz1 && sz3 <= sz2 &&
            sz1 <= 2 * sz3 && sz2 <= 2 * sz3)
          update_ans();
      }
    }
  }
  for (i = 1; i <= ind1; i++) ans[arr[i].second] = 1;
  for (i = ind1 + 1; i <= ind2; i++) ans[arr[i].second] = 2;
  for (i = ind2 + 1; i <= ind3; i++) ans[arr[i].second] = 3;
  for (i = ind3 + 1; i <= n; i++) ans[arr[i].second] = -1;
  for (i = 1; i <= n; i++) cout << ans[i] << " ";
  return 0;
}
