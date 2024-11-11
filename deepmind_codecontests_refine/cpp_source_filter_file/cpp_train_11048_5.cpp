#include <bits/stdc++.h>
using namespace std;
long long n;
pair<long long, long long> verify;
bitset<1001> veri;
map<pair<long long, long long>, long long> ver;
vector<pair<long long, long long> > ob;
bool search() {
  bool bad;
  pair<long long, long long> temp;
  for (long long t = 1; t < n; t++) {
    temp.first = verify.first - ob[t].first;
    temp.second = verify.second - ob[t].second;
    if (veri[ver[temp]]) {
      veri[ver[temp]] = 0;
    } else {
      bad = false;
      t = n;
    }
  }
  if (bad) {
    return true;
  }
  return false;
}
int main() {
  long long t;
  vector<pair<long long, long long> > clue;
  pair<long long, long long> temp;
  cin >> n;
  for (t = 0; t < n; t++) {
    cin >> temp.first >> temp.second;
    ob.push_back(temp);
  }
  for (t = 0; t < n; t++) {
    cin >> temp.first >> temp.second;
    clue.push_back(temp);
    ver[temp] = t;
  }
  for (t = 0; t < n; t++) {
    veri.set();
    veri[t] = 0;
    verify.first = ob[0].first + clue[t].first;
    verify.second = ob[0].second + clue[t].second;
    if (search()) {
      t = n;
    }
  }
  cout << verify.first << " " << verify.second << endl;
  return 0;
}
