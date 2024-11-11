#include <bits/stdc++.h>
using namespace std;
const int MN = 1e5 + 10;
struct trip {
  int X, Y, id;
} arr[MN];
bool cmp(const trip &a, const trip &b) { return a.X < b.X; }
long long sm1 = 0, sm2 = 0;
vector<int> ans;
int n;
long long cur1 = 0, cur2 = 0;
int main() {
  ios_base ::sync_with_stdio(false), cout.tie(0), cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> arr[i].X, sm1 += arr[i].X, arr[i].id = i;
  for (int i = 0; i < n; ++i) cin >> arr[i].Y, sm2 += arr[i].Y;
  if (n == 1) return cout << "1\n1\n", 0;
  sort(arr, arr + n, cmp);
  for (int i = 0; i < n; i += 2) {
    cur1 += arr[i].X;
    cur2 += arr[i].Y;
    ans.push_back(arr[i].id);
  }
  if (n % 2 == 0) {
    ans.push_back(arr[n - 1].id);
    cur1 += arr[n - 1].X;
    cur2 += arr[n - 1].Y;
  }
  if (cur1 > sm1 / 2 && cur2 > sm2 / 2) {
    sort(ans.begin(), ans.end());
    cout << ((int)(ans).size()) << '\n';
    for (auto x : ans) cout << x + 1 << ' ';
    cout << '\n';
    return 0;
  }
  ans.clear();
  cur1 = cur2 = 0;
  for (int i = 1; i < n; i += 2) {
    cur1 += arr[i].X, cur2 += arr[i].Y;
    ans.push_back(arr[i].id);
  }
  cur1 += arr[0].X, cur2 += arr[0].Y;
  ans.push_back(arr[0].id);
  sort(ans.begin(), ans.end());
  cout << ((int)(ans).size()) << '\n';
  for (auto x : ans) cout << x + 1 << ' ';
  cout << '\n';
  return 0;
}
