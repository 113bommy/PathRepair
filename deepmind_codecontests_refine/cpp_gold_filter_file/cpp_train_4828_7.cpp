#include <bits/stdc++.h>
using namespace std;
const long long hashBase = 31337LL;
const int maxLen = 300224;
long long hashVal[3][maxLen], currHash[maxLen];
long long power[maxLen];
int perm[3], n = 3;
string str[3], currAns;
void makeHash() {
  for (int i = 0; i < n; i++) hashVal[i][0] = str[i][0];
  for (int i = 0; i < n; i++)
    for (int j = 1; j < str[i].size(); j++)
      hashVal[i][j] = hashVal[i][j - 1] * hashBase + str[i][j];
  power[0] = 1;
  for (int i = 1; i < maxLen; i++) power[i] = power[i - 1] * hashBase;
}
void makeCurrHash() {
  if (currAns.empty()) return;
  currHash[0] = currAns[0];
  for (int i = 1; i < currAns.size(); i++)
    currHash[i] = currHash[i - 1] * hashBase + currAns[i];
}
inline bool getHash(int i, int j) {
  long long first = hashVal[perm[i]][j];
  long long second;
  int j1 = currAns.size() - j - 1;
  if (j1 == 0)
    second = currHash[currAns.size() - 1];
  else
    second = currHash[currAns.size() - 1] -
             currHash[j1 - 1] * power[currAns.size() - 1 - (j1 - 1)];
  return (first == second);
}
bool in(string& str0, string& str1, int& idx0) {
  if (str0.size() > str1.size()) return false;
  long long first = hashVal[idx0][str0.size() - 1];
  for (int i = 0; i <= str1.size() - str0.size(); i++) {
    long long second = currHash[i + str0.size() - 1];
    if (i != 0)
      second -= currHash[i - 1] * power[i + str0.size() - 1 - (i - 1)];
    if (first == second) return true;
  }
  return false;
}
int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin >> str[0] >> str[1] >> str[2];
  makeHash();
  for (int i = 0; i < n; i++) perm[i] = i;
  int ans = 0;
  for (int i = 0; i < n; i++) ans += str[i].size();
  do {
    currAns = str[perm[0]];
    for (int i = 1; i < n; i++) {
      makeCurrHash();
      if (in(str[perm[i]], currAns, perm[i])) continue;
      int bestPos = -1;
      for (int j = 0; j < str[perm[i]].size(); j++) {
        if (j >= currAns.size()) break;
        if (getHash(i, j)) bestPos = j;
      }
      for (int j = bestPos + 1; j < str[perm[i]].size(); j++)
        currAns.push_back(str[perm[i]][j]);
    }
    ans = min(ans, (int)currAns.size());
  } while (next_permutation(perm, perm + n));
  cout << ans << endl;
  return 0;
}
