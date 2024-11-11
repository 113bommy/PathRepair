#include <bits/stdc++.h>
using namespace std;
int main() {
  ios ::sync_with_stdio(false);
  string s;
  vector<int> a[26];
  cin >> s;
  for (int i = int(0); i <= int(int((s).length()) - 1); ++i) {
    a[s[i] - 'a'].push_back(i);
  }
  int pivot = 0;
  for (int i = 25; i >= 0; i--) {
    if (int((a[i]).size()) != 0) {
      for (int j = 0; j < int((a[i]).size()); j++) {
        if (a[i][j] >= pivot) cout << (char)(i + 'a') << " ";
      }
      pivot = max(pivot, a[i].back());
    }
  }
  return 0;
}
