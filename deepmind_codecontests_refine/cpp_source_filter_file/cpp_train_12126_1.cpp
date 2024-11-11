#include <bits/stdc++.h>
using namespace std;
const int MAXN = 256;
int ind[MAXN];
bool visited[MAXN];
vector<char> gt[MAXN];
int main() {
  int n;
  cin >> n;
  bool isPossible = true;
  string lastAuthor;
  for (int i = 0; i < n; ++i) {
    string curAuthor;
    cin >> curAuthor;
    if (i > 0 && isPossible) {
      for (int j = 0; j < lastAuthor.length(); ++j) {
        if (j > curAuthor.length()) {
          isPossible = false;
          break;
        }
        if (lastAuthor[j] != curAuthor[j]) {
          gt[lastAuthor[j]].push_back(curAuthor[j]);
          ind[curAuthor[j]]++;
          break;
        }
      }
    }
    lastAuthor = curAuthor;
  }
  vector<char> ans;
  for (int i = 0; i < 26; ++i) {
    for (char c = 'a'; c <= 'z'; ++c) {
      if (ind[c] == 0) {
        ind[c] = -1;
        for (auto adj : gt[c]) {
          ind[adj]--;
        }
        ans.push_back(c);
        break;
      }
    }
  }
  if (!isPossible || ans.size() != 26) {
    cout << "Impossible" << endl;
  } else {
    cout << string(ans.begin(), ans.end()) << endl;
  }
  return 0;
}
