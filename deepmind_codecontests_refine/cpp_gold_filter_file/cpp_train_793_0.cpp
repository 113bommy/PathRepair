#include <bits/stdc++.h>
using namespace std;
template <typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;
template <typename T>
using maxpq = priority_queue<T, vector<T>, less<T>>;
template <typename T1, typename T2>
struct pair_hash {
  size_t operator()(const pair<T1, T2> &p) const {
    return 31 * hash<T1>{}(p.first) + hash<T2>{}(p.second);
  }
};
string S;
int freq[26], CNT[26];
vector<int> L[26];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> S;
  for (auto i = (0); i < (((int)(S).size())); i++) L[S[i] - 'a'].push_back(i);
  for (auto i = (0); i < (26); i++) {
    CNT[i] = 0;
    if (((int)(L[i]).size()) <= 1) {
      CNT[i] = ((int)(L[i]).size());
      continue;
    }
    for (auto j = (1); j < (((int)(S).size())); j++) {
      for (auto k = (0); k < (26); k++) freq[k] = 0;
      for (auto k = (0); k < (((int)(L[i]).size())); k++)
        freq[S[(L[i][k] + j) % ((int)(S).size())] - 'a']++;
      int cnt = 0;
      for (auto k = (0); k < (26); k++) cnt += (freq[k] == 1);
      ((CNT[i]) = max((CNT[i]), (cnt)));
      if (CNT[i] == ((int)(L[i]).size())) break;
    }
  }
  int cnt = 0;
  for (auto i = (0); i < (26); i++) cnt += CNT[i];
  cout << setprecision(9) << fixed
       << ((double)cnt) / ((double)((int)(S).size())) << '\n';
  return 0;
}
