#include <bits/stdc++.h>
using namespace std;
int const IDMAX = 4e5;
int nId;
map<string, int> strToId;
string idToStr[1 + IDMAX];
int convertStrToId(string s) {
  if (strToId.find(s) != strToId.end()) {
    return strToId[s];
  } else {
    nId++;
    strToId[s] = nId;
    idToStr[nId] = s;
    return nId;
  }
}
vector<int> g[1 + IDMAX];
int inDeg[1 + IDMAX], outDeg[1 + IDMAX];
int startForEulerPath() {
  int start = 1;
  int nPlus = 0;
  int nMinus = 0;
  for (int i = 1; i <= nId; i++) {
    int dif = outDeg[i] - inDeg[i];
    if (dif <= -2 || dif >= 2) {
      return -1;
    } else if (dif == 1) {
      start = i;
      nPlus++;
    } else if (dif == -1) {
      nMinus++;
    }
  }
  if ((nPlus == 0 && nMinus == 0) || (nPlus == 1 && nMinus == 1)) {
    return start;
  }
  return -1;
}
vector<int> output;
void euler(int from) {
  while (!g[from].empty()) {
    int to = g[from].back();
    g[from].pop_back();
    euler(to);
  }
  output.push_back(from);
}
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    string str, prefix, suffix;
    cin >> str;
    prefix = str.substr(0, 2);
    int prefixId = convertStrToId(prefix);
    suffix = str.substr(1, 2);
    int suffixId = convertStrToId(suffix);
    g[prefixId].push_back(suffixId);
    outDeg[prefixId]++;
    inDeg[suffixId]++;
  }
  int start = startForEulerPath();
  if (start == -1) {
    cout << "NO\n";
    return 0;
  } else {
    euler(start);
    if (output.size() < n + 2) {
      cout << "NO\n";
      return 0;
    }
    string ans = idToStr[output[output.size() - 1]];
    for (int i = output.size() - 2; i >= 0; i--) {
      string s = idToStr[output[i]];
      ans.push_back(s[1]);
    }
    cout << "YES\n" << ans;
  }
  return 0;
}
