#include <bits/stdc++.h>
using namespace std;
int n, m, k;
string s;
long long ans;
bool flag;
void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto i = 0; i < n; i++) cin >> a[i];
  ;
  unordered_map<int, int> m;
  int val;
  int mini = INT_MIN;
  for (auto i = 0; i < n; i++) {
    m[a[i]]++;
    if (mini < m[a[i]]) {
      mini = m[a[i]];
      val = a[i];
    }
  }
  vector<int> ind;
  int count = n;
  vector<bool> done(n, false);
  for (auto i = 0; i < n; i++) {
    if (a[i] == val) {
      ind.push_back(i);
      done[i] = true;
      count--;
    }
  }
  cout << count << endl;
  sort(ind.begin(), ind.end());
  if (count == 0) return;
  for (int j = ind[0]; j > 0; j--) {
    int i = j - 1;
    if (a[i] > a[j])
      cout << 2 << ' ';
    else
      cout << 1 << ' ';
    cout << i + 1 << ' ' << j + 1 << "\n";
    done[i] = true;
  }
  for (int j = ind[0]; j < n - 1; j++) {
    int i = j + 1;
    if (!done[i]) {
      if (a[i] > a[j])
        cout << 2 << ' ';
      else
        cout << 1 << ' ';
      cout << i + 1 << ' ' << j + 1 << "\n";
      done[i] = true;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
