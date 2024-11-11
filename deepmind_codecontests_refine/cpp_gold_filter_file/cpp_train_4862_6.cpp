#include <bits/stdc++.h>
using namespace std;
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << " : " << arg1 << " | ";
  __f(comma + 1, args...);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, i, j, cnt[300100], mark[300100];
  cin >> n;
  vector<string> a;
  for (__typeof(n) i = (0) - ((0) > (n)); i != (n) - ((0) > (n));
       i += 1 - 2 * ((0) > (n))) {
    string l;
    cin >> l;
    a.push_back(l);
  }
  for (__typeof(n) i = (0) - ((0) > (n)); i != (n) - ((0) > (n));
       i += 1 - 2 * ((0) > (n))) {
    string l = a[i];
    int count = 0, mn = INT_MAX, np = 0;
    for (__typeof(l.end()) j = (l.begin()) - ((l.begin()) > (l.end()));
         j != (l.end()) - ((l.begin()) > (l.end()));
         j += 1 - 2 * ((l.begin()) > (l.end()))) {
      if (*j == '(')
        count++;
      else
        count--;
      mn = min(mn, count);
    }
    if (mn < 0 && count > mn) np = 1;
    mark[i] = np;
    cnt[i] = count;
  }
  map<int, vector<int>> mp;
  for (__typeof(n) i = (0) - ((0) > (n)); i != (n) - ((0) > (n));
       i += 1 - 2 * ((0) > (n))) {
    if (mark[i] == 0) {
      mp[cnt[i]].push_back(i);
    }
  }
  long long int sum = 0;
  for (auto i = mp.begin(); i != mp.end(); i++) {
    if (i->first == 0) {
      sum += (long long int)(i->second.size()) * (i->second.size());
    } else if (i->first > 0) {
      auto it = mp.find(-(i->first));
      if (it != mp.end()) {
        sum += (long long int)(i->second.size()) * (it->second.size());
      }
    }
  }
  cout << sum << endl;
}
