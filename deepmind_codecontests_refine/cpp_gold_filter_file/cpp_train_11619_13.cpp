#include <bits/stdc++.h>
using namespace std;
template <class T>
void prll(vector<T> s) {
  for (long long i = 0; i < s.size(); i++) cout << s[i] << " ";
  cout << endl;
}
template <class T>
void prll(vector<pair<T, T> > s) {
  for (long long i = 0; i < s.size(); i++)
    cout << s[i].first + 1 << " " << s[i].second + 1 << endl;
  ;
  cout << endl;
}
template <class T>
void prll(vector<vector<T> > s) {
  for (long long i = 0; i < s.size(); i++) prll(s[i]);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  srand(time(NULL));
  int n, m;
  cin >> n >> m;
  vector<int> s(n);
  vector<int> lst(n);
  for (int i = 0; i < n; i++) {
    cin >> s[i];
    s[i]--;
    lst[s[i]] = i;
  }
  for (int i = 0; i < m; i++) {
    int l, r, x;
    cin >> l >> r >> x;
    l--;
    r--;
    x--;
    if (x < l || x > r) {
      cout << "Yes" << endl;
      continue;
    }
    int cnt = 0;
    for (int j = l; j <= r; j++) {
      if (s[j] < s[x]) cnt++;
    }
    if (x == l + cnt)
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
  }
  return 0;
}
