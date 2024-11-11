#include <bits/stdc++.h>
using namespace std;
struct data {
  char ch;
  int cnt;
} arr[26];
int comp1(data a, data b) {
  if (a.cnt < b.cnt)
    return 1;
  else
    return 0;
}
int comp2(data a, data b) {
  if (a.ch < b.ch)
    return 1;
  else
    return 0;
}
int main() {
  int len, ans, i, k, temp;
  char ch;
  string str;
  cin >> str;
  cin >> k;
  len = str.length();
  ans = 26;
  for (i = 0; i < 26; i++) {
    arr[i].cnt = 0;
    arr[i].ch = 'a' + i;
  }
  for (i = 0; i < len; i++) {
    ch = str[i];
    arr[ch - 'a'].cnt++;
  }
  sort(arr, arr + 26, comp1);
  i = 0;
  while (k > 0 && i < 26) {
    temp = k - arr[i].cnt;
    if (temp >= 0) {
      arr[i].cnt = 0;
      k = temp;
      ans--;
      i++;
    } else
      break;
  }
  sort(arr, arr + 26, comp2);
  cout << ans << "\n";
  for (i = 0; i < len; i++) {
    ch = str[i];
    if (arr[ch - 'a'].cnt > 0) cout << ch;
  }
  cout << "\n";
}
