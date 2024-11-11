#include <bits/stdc++.h>
using namespace std;
int arr[100005], l = -1000000000, r = 1000000000, cur = 0, n;
bitset<100005> bs;
char ch;
int min(int pos) {
  return min(arr[pos], min(min(arr[pos - 1], arr[pos - 2]),
                           min(arr[pos - 3], arr[pos - 4])));
}
int max(int pos) {
  return max(arr[pos], max(max(arr[pos - 1], arr[pos - 2]),
                           max(arr[pos - 3], arr[pos - 4])));
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> arr[i];
  for (int i = 0; i < n; i++) cin >> ch, bs[i] = (ch == '1');
  for (int i = 0; i < n; i++)
    if (bs[i] != cur) {
      cur = bs[i];
      if (bs[i])
        l = max(l, max(i) + 1);
      else
        r = min(r, min(i) - 1);
    }
  cout << l << " " << r << endl;
  return 0;
}
