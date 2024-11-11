#include <bits/stdc++.h>
using namespace std;
string S, SS;
vector<int> ans;
int total[500], total2[500];
void Shift(int k) {
  string ss = "";
  int i, j;
  for (i = SS.size() - 1, j = 1; j <= k; i--, j++) ss += SS[i];
  for (j = 0; j <= i; j++) ss += SS[j];
  SS = ss;
  ans.push_back(k);
}
int main() {
  int n;
  cin >> n >> S >> SS;
  for (int i = 0; i < S.size(); i++) {
    total[S[i]]++;
    total2[SS[i]]++;
  }
  for (int i = 'a'; i <= 'z'; i++) {
    if (total[i] != total2[i]) {
      cout << "-1";
      return 0;
    }
  }
  for (int i = 0, k = S.size() - 1; i < S.size(); i++, k--) {
    int pos;
    for (int j = i; j < SS.size(); j++) {
      if (SS[j] == S[k]) {
        pos = j;
        break;
      }
    }
    Shift(n);
    Shift(pos);
    Shift(1);
  }
  cout << ans.size() << endl;
  for (int i = 0; i < ans.size(); i++) {
    printf("%d ", ans[i]);
  }
}
