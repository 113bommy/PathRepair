#include <bits/stdc++.h>
using namespace std;
int main(void) {
  int nBranches;
  cin >> nBranches;
  vector<string> vBranches;
  for (int i = 0; i < nBranches; ++i) {
    string branch;
    cin >> branch;
    vBranches.push_back(branch);
  }
  char sep;
  cin >> sep;
  for (int i = 0; i < nBranches; ++i) vBranches[i] += sep;
  sort(vBranches.begin(), vBranches.end(), greater<string>());
  int length = 0;
  vector<string *> v[10];
  for (int i = 0; i < nBranches; ++i) {
    int len = (int)(vBranches[i].size() - 1);
    v[len - 1].push_back(&(vBranches[i]));
    length += len;
  }
  length /= nBranches / 2;
  for (int i = nBranches - 1; i >= 0; --i) {
    if (vBranches[i].empty()) continue;
    cout << vBranches[i];
    int len = vBranches[i].size() - 1;
    int lenLeft = length - len - 1;
    vBranches[i].clear();
    while (v[lenLeft].back()->empty()) v[lenLeft].pop_back();
    v[lenLeft].back()->at(lenLeft + 1) = '\n';
    cout << *(v[lenLeft].back());
    v[lenLeft].back()->clear();
    v[lenLeft].pop_back();
  }
  return 0;
}
