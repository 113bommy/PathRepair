#include <bits/stdc++.h>
using namespace std;
long long int arr[1000001], cnt[1000001];
vector<int> crr;
int ans[25][25];
int cnt1[1000001], cnt2[1000001];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, a, b;
  cin >> n;
  for (int i = 0; i < n * n; i++) {
    cin >> arr[i];
    cnt[arr[i]]++;
    cnt1[arr[i]]++;
    cnt2[arr[i]]++;
  }
  int freq4 = 0, freq2 = 0, freq1 = 0;
  for (int i = 1; i < 1000; ++i) {
    if (cnt[i] != 0) {
      freq4 += (cnt[i] / 4);
      cnt[i] = (cnt[i] % 4);
      freq2 += (cnt[i] / 2);
      cnt[i] = (cnt[i] % 2);
      freq1 += (cnt[i] / 1);
      cnt[i] = (cnt[i] / 1);
    }
  }
  int nfreq4 = 0, nfreq2 = 0, nfreq1 = 0;
  if (n % 2 == 0) {
    nfreq4 = (n / 2);
    nfreq4 *= (n / 2);
  } else {
    nfreq4 = (n / 2);
    nfreq4 *= (n / 2);
    nfreq2 = (n - 1);
    nfreq1 = 1;
  }
  if (n % 2 == 0) {
    if (nfreq4 != freq4) {
      cout << "NO" << endl;
      return 0;
    } else {
      cout << "YES" << endl;
      for (int i = 1; i < 10001; ++i) {
        while (cnt1[i] % 4 == 0 && cnt1[i] > 0) {
          crr.push_back(i);
          cnt1[i] -= 4;
        }
      }
      int u = 0;
      for (int i = 1; i <= n / 2; ++i) {
        for (int j = 1; j <= n / 2; ++j) {
          ans[i][j] = crr[u];
          ans[n + 1 - i][j] = crr[u];
          ans[n + 1 - i][n + 1 - j] = crr[u];
          ans[i][n + 1 - j] = crr[u];
          u++;
        }
      }
      for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
          cout << ans[j][i] << " ";
        }
        cout << endl;
      }
      return 0;
    }
  } else {
    if (nfreq4 > freq4) {
      cout << "NO" << endl;
      return 0;
    }
    freq2 += 2 * (freq4 - nfreq4);
    if (nfreq2 > freq2) {
      cout << "NO" << endl;
      return 0;
    }
    freq1 += 2 * (nfreq2 - freq2);
    if (nfreq1 > freq1) {
      cout << "NO" << endl;
      return 0;
    }
    vector<int> crr4;
    vector<int> crr2;
    vector<int> crr1;
    cout << "YES" << endl;
    for (int i = 1; i < 10001; ++i) {
      int bm = cnt2[i] / 4;
      int er = 0;
      while (bm && nfreq4 > 0) {
        er += 4;
        crr4.push_back(i);
        bm--;
        nfreq4--;
      }
      cnt2[i] -= er;
    }
    for (int i = 1; i < 10001; ++i) {
      int bm = cnt2[i] / 2;
      int er = 0;
      while (bm && nfreq2 > 0) {
        er += 2;
        crr2.push_back(i);
        bm--;
        nfreq2--;
      }
      cnt2[i] -= er;
    }
    for (int i = 1; i < 10001; ++i) {
      if (cnt2[i] == 1) crr1.push_back(i);
    }
    int p = 0;
    for (int i = 1; i <= n / 2; ++i) {
      for (int j = 1; j <= n / 2; ++j) {
        ans[i][j] = crr4[p];
        ans[n + 1 - i][j] = crr4[p];
        ans[n + 1 - i][n + 1 - j] = crr4[p];
        ans[i][n + 1 - j] = crr4[p];
        p++;
      }
    }
    p = 0;
    for (int i = 1; i <= n / 2; ++i) {
      ans[(n / 2) + 1][i] = crr2[p];
      ans[(n / 2) + 1][n + 1 - i] = crr2[p];
      p++;
    }
    for (int i = 1; i <= n / 2; ++i) {
      ans[i][(n / 2) + 1] = crr2[p];
      ans[n + 1 - i][(n / 2) + 1] = crr2[p];
      p++;
    }
    ans[(n / 2) + 1][(n / 2) + 1] = crr1[0];
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        cout << ans[j][i] << " ";
      }
      cout << endl;
    }
    return 0;
  }
  return 0;
}
