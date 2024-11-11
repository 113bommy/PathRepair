#include <bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")
using namespace std;
const int N = 100007;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  string str;
  cin >> str;
  long long k;
  cin >> k;
  if (k >= str.length()) {
    cout << 0 << endl;
    cout << endl;
  } else {
    unordered_map<char, int> amp;
    for (int i = 0; i < str.length(); i++) {
      amp[str[i]]++;
    }
    vector<pair<int, char>> v;
    for (auto i = amp.begin(); i != amp.end(); i++) {
      v.push_back(make_pair(i->second, i->first));
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++) {
      if (amp.size() == 1) {
        break;
      }
      if (v[i].first > k) {
        v[i].first = v[i].first - k;
        k = 0;
        amp[v[i].second] = v[i].first;
      } else {
        k = k - v[i].first;
        v[i].first = 0;
        amp.erase(v[i].second);
      }
    }
    string str2;
    str2.clear();
    int k = amp.size();
    for (int i = 0; i < str.size(); i++) {
      if (amp[str[i]]) {
        str2.push_back(str[i]);
        amp[str[i]]--;
      }
    }
    cout << k << endl;
    cout << str2 << endl;
  }
}
