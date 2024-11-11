#include <bits/stdc++.h>
using namespace std;
vector<int> rref(vector<int>& v, vector<pair<int, int> >& moves) {
  int row = 0;
  vector<int> x;
  for (int j = 29; row < (int)(v).size() && j >= 0; j--) {
    for (int i = row; i < (int)(v).size(); i++) {
      if (v[i] & (1 << j)) {
        if (i > row) {
          swap(v[i], v[row]);
          moves.push_back({i, row});
          moves.push_back({row, i});
          moves.push_back({i, row});
        }
        break;
      }
    }
    if ((v[row] & (1 << j)) == 0) continue;
    x.push_back(1 << j);
    for (int i = 0; i < (int)(v).size(); i++) {
      if (i == row) continue;
      if (v[i] & (1 << j)) {
        v[i] ^= v[row];
        moves.push_back({i, row});
      }
    }
    row++;
  }
  return x;
}
bool convertbases(vector<int>& ax, vector<int>& bx, vector<int>& a,
                  vector<int>& b, vector<pair<int, int> >& cm) {
  if ((int)(ax).size() < (int)(bx).size()) return false;
  int j = 0;
  for (int i = 0; i < (int)(ax).size(); i++) {
    if (j == (int)(bx).size()) {
      a[i] = 0;
      cm.push_back({i, i});
      continue;
    }
    if (ax[i] > bx[j]) {
      a[i] = 0;
      cm.push_back({i, i});
      continue;
    }
    if (ax[i] < bx[j]) return false;
    int want = a[i] ^ b[j];
    for (int k = i + 1; k < (int)(ax).size(); k++) {
      if (want & (ax[k])) {
        want ^= a[k];
        cm.push_back({i, k});
        a[i] ^= a[k];
      }
    }
    if (want) return false;
    j++;
  }
  if (j != (int)(bx).size()) return false;
  for (int i = (int)(ax).size() - 1; i >= 0; i--) {
    if (a[i] == 0) {
      for (int k = i + 1; k < (int)(ax).size(); k++) {
        a[k] = a[k + 1];
        cm.push_back({k, k + 1});
        cm.push_back({k + 1, k + 1});
      }
      ax.pop_back();
    }
  }
  return true;
}
void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> b(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) cin >> b[i];
  vector<pair<int, int> > am, bm;
  vector<int> ax = rref(a, am);
  vector<int> bx = rref(b, bm);
  vector<pair<int, int> > cm;
  if (!convertbases(ax, bx, a, b, cm))
    cout << "-1\n";
  else {
    reverse(bm.begin(), bm.end());
    cout << (int)(am).size() + (int)(cm).size() + (int)(bm).size() << "\n";
    for (pair<int, int> out : am)
      cout << out.first + 1 << " " << out.second + 1 << "\n";
    for (pair<int, int> out : cm)
      cout << out.first + 1 << " " << out.second + 1 << "\n";
    for (pair<int, int> out : bm)
      cout << out.first + 1 << " " << out.second + 1 << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  solve();
}
