#include <bits/stdc++.h>
char _;
using namespace std;
template <typename T1, typename T2>
inline int max(T1 a, T2 b) {
  return (a > b ? a : b);
}
template <typename T1, typename T2>
inline int min(T1 a, T2 b) {
  return (a < b ? a : b);
}
const int MAX = 10 + 5;
int cnt[MAX];
char arr[MAX];
int32_t main() {
  int n;
  string s;
  cin >> n >> s;
  arr[0] = 'A';
  arr[1] = 'C';
  arr[2] = 'G';
  arr[3] = 'T';
  arr[4] = '?';
  for (int i = 0; i < n; i++)
    for (int j = 0; j < 5; j++)
      if (s[i] == arr[j]) cnt[j]++;
  int max_cnt = 0;
  for (int i = 0; i < 4; i++) max_cnt = max(max_cnt, cnt[i]);
  for (int i = 0; i < 4; i++) cnt[i] = max_cnt - cnt[i];
  for (int i = 0; i < n; i++)
    if (s[i] == '?') {
      bool h = 0;
      for (int j = 0; j < 4; j++)
        if (cnt[j] > 0) {
          s[i] = arr[j];
          cnt[j]--;
          h = 1;
          break;
        }
      if (h) continue;
      cnt[1] = cnt[2] = cnt[3] = 1;
      s[i] = arr[0];
    }
  if (cnt[0] == 0 && cnt[1] == 0 && cnt[2] == 0 && cnt[3] == 0) {
    cout << s << endl;
    return 0;
  }
  cout << "===" << endl;
  return 0;
}
