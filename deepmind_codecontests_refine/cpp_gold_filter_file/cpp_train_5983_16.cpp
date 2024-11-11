#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  int n, cursor;
  string s;
  cin >> n >> cursor;
  cin >> s;
  int cost = 0;
  for (int i = 0; i < n / 2; i++) {
    vector<char> arr(2);
    arr[0] = s[i];
    arr[1] = s[n - i - 1];
    sort(arr.begin(), arr.begin() + 2);
    cost += min(arr[1] - arr[0], 'z' - arr[1] + 1 + arr[0] - 'a');
  }
  cursor -= 1;
  int end = n / 2 - 1;
  int start = 0;
  while (start < n && s[start] == s[n - start - 1]) {
    ++start;
  }
  while (end > 0 && s[end] == s[n - end - 1]) {
    --end;
  }
  if (start > end) {
    cout << 0;
    return 0;
  }
  if (cursor >= n / 2) {
    cursor = n - cursor - 1;
  }
  cost += min(abs(end - cursor), abs(cursor - start)) + end - start;
  cout << cost;
  return 0;
}
