#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
const long long MOD = 1e9 + 7;
const double eps = 1e-9;
int n;
vector<pair<string, pair<int, int> > > s(11);
bool dif_dig(int num) {
  if (num <= 100) num *= 10;
  bool dig[11] = {0};
  while (num > 0) {
    if (dig[num % 10]) return false;
    dig[num % 10] = true;
    num /= 10;
  }
  return true;
}
bool satisfies(int num) {
  int arr[] = {0, 0, 0, 0};
  int index = 3;
  while (num > 0) {
    arr[index--] = num % 10;
    num /= 10;
  }
  for (int i = 0; i < n; i++) {
    int match = 0, missmatch = 0;
    for (int j = 0; j < 4; j++) {
      for (int k = 0; k < 4; k++) {
        if (s[i].first[j] == (char)(arr[k] + '0')) {
          if (j == k)
            match++;
          else
            missmatch++;
        }
      }
    }
    if (match != s[i].second.first or missmatch != s[i].second.second)
      return false;
  }
  return true;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> s[i].first >> s[i].second.first >> s[i].second.second;
  }
  int tot = 0, ans = -1;
  for (int i = 123; i <= 9999; i++) {
    if (!dif_dig(i)) continue;
    if (satisfies(i)) {
      tot++;
      ans = i;
    }
  }
  if (tot == 0)
    cout << "Incorrect data"
         << "\n";
  else if (tot == 1)
    cout << (ans < 1000 ? "0" : "") << ans << "\n";
  else
    cout << "Need more data"
         << "\n";
}
