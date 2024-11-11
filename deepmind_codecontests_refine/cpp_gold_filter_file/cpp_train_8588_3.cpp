#include <bits/stdc++.h>
using namespace std;
int lg2(const int &x) { return 31 - __builtin_clz(x); }
long long int lg2(const long long int &x) { return 63 - __builtin_clzll(x); }
char alpha[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i',
                  'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r',
                  's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
string s;
int t;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  vector<pair<int, int>> vec(n);
  pair<int, int> tmp;
  for (int i = 0; i < n; i++) {
    cin >> vec[i].second >> vec[i].first;
  }
  sort(vec.begin(), vec.end());
  int ans = 1;
  tmp = vec[0];
  for (int i = 1; i < n; i++) {
    if (vec[i].second > tmp.first) {
      ans++;
      tmp = vec[i];
    }
  }
  cout << ans << '\n';
}
