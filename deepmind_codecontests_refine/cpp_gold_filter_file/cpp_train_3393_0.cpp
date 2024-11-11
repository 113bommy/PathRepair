#include <bits/stdc++.h>
using namespace std;
vector<string> strs;
size_t hashes[50][50];
int main() {
  int n;
  cin >> n;
  string str;
  while (n--) cin >> str, strs.push_back(str);
  std::hash<std::string> shash;
  for (int s = 0; s < strs.size(); ++s) {
    string tmp = strs[s];
    for (int i = 0; i < strs[s].size(); ++i) {
      tmp = tmp.substr(1) + tmp[0];
      hashes[s][i] = shash(tmp);
    }
  }
  int r = 0x3f3f3f3f;
  int len = strs[0].size();
  for (int i = 0; i < strs.size(); ++i) {
    int K = 0;
    for (int j = 0; j < strs.size(); ++j) {
      int k = 0;
      while (k < len && hashes[j][k] != hashes[i][0]) k++;
      if (k == len) {
        K = -1;
        break;
      } else
        K += k;
    }
    r = min(r, K);
  }
  cout << r << endl;
  return 0;
}
