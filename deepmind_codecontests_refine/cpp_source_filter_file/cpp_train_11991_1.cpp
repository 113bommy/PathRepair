#include <bits/stdc++.h>
using namespace std;
string s, t;
vector<long long> v[26];
long long pos[200005];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> s >> t;
  for (long long i = (long long)0; i < (long long)(long long)s.size(); i++)
    v[s[i] - 'a'].push_back(i);
  long long i = 0, j = 0;
  while (j < (long long)t.size()) {
    if (s[i] == t[j]) {
      pos[j] = i;
      j++;
    }
    i++;
  }
  pos[t.size()] = s.size();
  long long ans = s.size() - i;
  for (int i = t.size() - 1; i >= 0; i--) {
    pos[i] = v[t[i] - 'a'][lower_bound(v[t[i] - 'a'].begin(),
                                       v[t[i] - 'a'].end(), pos[i + 1]) -
                           v[t[i] - 'a'].begin() - 1];
    if (i)
      ans = max(ans, pos[i + 1] - pos[i] - 1);
    else
      ans = max(ans, pos[i]);
  }
  cout << ans;
}
