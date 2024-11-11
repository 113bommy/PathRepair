#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int sum_L = 0;
void resize_L(int new_size, multiset<int>& L, multiset<int>& R) {
  while (((int)L.size()) < new_size) {
    int val = *R.begin();
    sum_L += val;
    L.insert(val);
    R.erase(R.begin());
  }
  while (((int)L.size()) > new_size) {
    int val = *L.rbegin();
    sum_L -= val;
    L.erase(prev(L.end()));
    R.insert(val);
  }
}
void remove(int val, multiset<int>& L, multiset<int>& R) {
  if (L.find(val) != L.end()) {
    L.erase(L.find(val));
    sum_L -= val;
  } else if (R.find(val) != R.end()) {
    R.erase(R.find(val));
  }
}
void solve() {
  cin >> n >> m >> k;
  multiset<int> L, R;
  vector<pair<int, int> > oo, zo, oz, zz;
  int sum_oo = 0;
  for (int i = 0; i < n; i++) {
    int t, a, b;
    cin >> t >> a >> b;
    if (a and b) {
      oo.push_back({t, i + 1});
    } else {
      if (a)
        oz.push_back({t, i + 1});
      else if (b)
        zo.push_back({t, i + 1});
      else {
        zz.push_back({t, i + 1});
        R.insert(t);
      }
    }
  }
  sort(oo.begin(), oo.end());
  sort(oz.begin(), oz.end());
  sort(zo.begin(), zo.end());
  for (auto x : oz) R.insert(x.first);
  for (auto x : zo) R.insert(x.first);
  int ans = 2000000005;
  int ptr_oz = 0, ptr_zo = 0;
  int sum_oz = 0, sum_zo = 0;
  for (int i = 0; i <= min(m, ((int)oo.size())) - 1; i++) sum_oo += oo[i].first;
  int c_oo, c_ozo;
  for (int i = min(m, ((int)oo.size())) - 1; i >= -1;
       (~i ? sum_oo -= oo[i].first : 0), i--) {
    int req_per = max(0, k - i - 1);
    if (req_per * 2 + i + 1 > m) continue;
    if (req_per > min(((int)oz.size()), ((int)zo.size()))) continue;
    int rem = m - (req_per * 2 + i + 1);
    while (ptr_oz < req_per) {
      sum_oz += oz[ptr_oz].first;
      remove(oz[ptr_oz].first, L, R);
      ptr_oz++;
    }
    while (ptr_zo < req_per) {
      sum_zo += zo[ptr_zo].first;
      remove(zo[ptr_zo].first, L, R);
      ptr_zo++;
    }
    if (rem > ((int)L.size()) + ((int)R.size())) continue;
    resize_L(rem, L, R);
    int cur_res = sum_L + sum_oo + sum_oz + sum_zo;
    ans = min(ans, cur_res);
    if (ans == cur_res) {
      c_oo = i + 1;
      c_ozo = req_per;
    }
  }
  if (ans == 2000000005) {
    cout << -1 << "\n";
    return;
  }
  cout << ans << "\n";
  for (int i = 0; i < c_oo; i++) cout << oo[i].second << " ";
  for (int i = 0; i < c_ozo; i++)
    cout << oz[i].second << " " << zo[i].second << " ";
  int rem = m - c_ozo * 2 - c_oo;
  vector<pair<int, int> > others;
  for (int i = c_oo; i < ((int)oo.size()); i++) others.push_back(oo[i]);
  for (int i = c_ozo; i < ((int)oz.size()); i++) others.push_back(oz[i]);
  for (int i = c_ozo; i < ((int)zo.size()); i++) others.push_back(zo[i]);
  for (int i = 0; i < ((int)zz.size()); i++) others.push_back(zz[i]);
  sort(others.begin(), others.end());
  for (int i = 0; i < rem; i++) cout << others[i].second << ' ';
  cout << "\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  while (t--) solve();
}
