#include <bits/stdc++.h>
using namespace std;
int main() {
  long long i, min_, j, k, n, z, cnt, arr[30][30], ans[100005];
  for (i = 0; i < 30; i++) {
    for (j = 0; j < 30; j++) {
      arr[i][j] = 1123456789LL;
    }
  }
  string str1, str2, sx, sy, str, ch;
  cin >> str1 >> str2 >> n;
  for (i = 1; i <= n; i++) {
    cin >> sx >> sy >> z;
    arr[sx[0] - 96][sy[0] - 96] = min(z, arr[sx[0] - 96][sy[0] - 96]);
  }
  if (str1.length() != str2.length()) {
    cout << "-1";
    return 0;
  }
  for (k = 1; k <= 26; k++) {
    for (i = 1; i <= 26; i++) {
      for (j = 1; j <= 26; j++) {
        arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
      }
    }
  }
  cnt = 0;
  str = "";
  for (i = 0; i < str1.length(); i++) {
    if (str1[i] == str2[i]) {
      str = str + str1[i];
      continue;
    }
    min_ =
        min(arr[str1[i] - 96][str2[i] - 96], arr[str2[i] - 96][str1[i] - 96]);
    if (arr[str1[i] - 96][str2[i] - 96] < arr[str2[i] - 96][str1[i] - 96])
      ch = str2[i];
    else
      ch = str1[i];
    for (k = 1; k <= 26; k++) {
      if (min_ > arr[str1[i] - 96][k] + arr[str2[i] - 96][k]) {
        ch = k + 96;
        min_ = arr[str1[i] - 96][k] + arr[str2[i] - 96][k];
      }
    }
    if (min_ == 1123456789LL) {
      printf("-1");
      return 0;
    }
    cnt += min_;
    str = str + ch;
  }
  cout << cnt << endl;
  cout << str;
  return 0;
}
