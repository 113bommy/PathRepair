#include <bits/stdc++.h>
using namespace std;
const int p = 37;
unordered_map<long long, int> answers;
map<long long, vector<int> > hashes;
int lnA, lnB, q;
int check(int a, int b) {
  if (a < b)
    return max(a + lnA, b + lnB) - a;
  else
    return max(a + lnA, b + lnB) - b;
}
int main() {
  ios_base::sync_with_stdio(0);
  string s, a, b;
  cin >> s;
  for (int i = 0; i < (int)s.length(); i++) {
    long long hash = 0;
    for (int j = 0; j < 4 && (i + j < (int)s.length()); j++)
      hash = hash * p + s[i + j], hashes[hash].push_back(i);
  }
  cin >> q;
  while (q--) {
    cin >> a >> b;
    long long hashA = 0, hashB = 0;
    lnA = (int)a.length();
    lnB = (int)b.length();
    for (int i = 0; i < (int)a.length(); i++) hashA = hashA * p + a[i];
    for (int i = 0; i < (int)b.length(); i++) hashB = hashB * p + b[i];
    string c = a + "#$" + b;
    long long hashC = 0;
    for (int i = 0; i < (int)c.length(); i++) hashC = hashC * p + c[i];
    string d = b + "#$" + a;
    long long hashD = 0;
    for (int i = 0; i < (int)d.length(); i++) hashD = hashD * p + d[i];
    if (answers[hashC]) {
      cout << answers[hashC] << "\n";
      continue;
    }
    if (!(int)hashes[hashA].size() * (int)hashes[hashB].size()) {
      answers[hashC] = -1;
      answers[hashD] = -1;
      cout << -1 << "\n";
      continue;
    }
    vector<int> posA = hashes[hashA];
    vector<int> posB = hashes[hashB];
    vector<int>::iterator itA = posA.begin();
    vector<int>::iterator itB = posB.begin();
    int res = -1;
    while (itA != posA.end() && itB != posB.end()) {
      res = res != -1 ? min(res, check(*itA, *itB)) : check(*itA, *itB);
      if (*itA < *itB)
        itA++;
      else
        itB++;
    }
    cout << res << "\n";
    answers[hashC] = res;
    answers[hashD] = res;
  }
  return 0;
}
