#include <bits/stdc++.h>
using namespace std;
long long int fast_expo(long long int base, long long int exponent) {
  if (exponent == 0) return 1;
  if (exponent == 1)
    return base;
  else {
    if (exponent % 2 == 1) {
      return base * fast_expo(base, exponent - 1);
    } else {
      long long int half = fast_expo(base, exponent / 2);
      return half * half;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int n, k;
  cin >> n >> k;
  vector<long long int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  set<pair<long long int, long long int> > ni;
  for (int i = 0; i < n; i++) {
    ni.insert(make_pair(a[i], i));
  }
  set<long long int> index_set;
  for (int i = 0; i < n; i++) {
    index_set.insert(i);
  }
  pair<long long int, long long int> currmax;
  long long int team = 0;
  long long int count = 0;
  set<long long int>::iterator itr;
  vector<long long int> rem;
  vector<long long int> teams(n);
  while (!ni.empty()) {
    currmax = *prev(ni.end());
    rem.clear();
    itr = index_set.find(currmax.second);
    rem.push_back(currmax.second);
    count = 0;
    while (count < k) {
      if (itr == index_set.begin()) break;
      count++;
      --itr;
      rem.push_back(*itr);
    }
    count = 0;
    itr = index_set.find(currmax.second);
    while (count < k && itr != index_set.end()) {
      ++itr;
      if (itr == index_set.end()) break;
      count++;
      rem.push_back(*itr);
    }
    for (auto x : rem) {
      teams[x] = team;
      index_set.erase(index_set.find(x));
      ni.erase(ni.find(make_pair(a[x], x)));
    }
    team ^= 1;
  }
  for (int i = 0; i < n; i++) cout << teams[i] + 1 << " ";
  cout << "\n";
  return 0;
}
