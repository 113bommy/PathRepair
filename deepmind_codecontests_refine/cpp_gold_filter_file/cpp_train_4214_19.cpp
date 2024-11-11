#include <bits/stdc++.h>
using namespace std;
int test = 1;
bool check(vector<int> no) {
  sort(no.begin(), no.end());
  int mx = no[3] - no[0];
  int sm = accumulate(no.begin(), no.end(), 0);
  bool ans = ((sm / 4) == mx);
  ans = ans && (sm % 4 == 0);
  ans = ans && ((no[1] + no[2]) / 2 == mx);
  ans = ans && ((no[1] + no[2]) % 2 == 0);
  return ans;
}
void solve() {
  int N;
  cin >> N;
  vector<int> no(4);
  for (int i = 0; i < N; i++) cin >> no[i];
  if (N == 4) {
    bool ans = check(no);
    cout << (ans ? "YES" : "NO") << endl;
    return;
  }
  if (N == 3) {
    bool ans = false;
    for (int i = 1; i <= 1000000; i++) {
      no[3] = i;
      ans = check(no);
      if (ans) {
        cout << (ans ? "YES" : "NO") << endl;
        cout << i << endl;
        return;
      }
    }
    cout << "NO" << endl;
    return;
  }
  if (N == 2 || N == 1) {
    vector<int> copy = no;
    if (N == 1) no[1] = no[0];
    bool ans = false;
    for (int k = 1; k < 2; k++) {
      for (int i = 1; i < 1501; i++) {
        if (ans) break;
        no[2] = i;
        for (int j = 1; j < 1501; j++) {
          if (ans) break;
          no[3] = j;
          ans = ans || (check(no));
          if (ans) {
            cout << "YES" << endl;
            cout << i << endl << j << endl;
            if (N == 1) cout << no[1] << endl;
            return;
          }
        }
      }
    }
    cout << "NO" << endl;
    return;
  }
  if (N == 0) {
    cout << "YES" << endl << "1\n1\n3\n3\n";
  }
}
int main() {
  for (int i = 0; i < test; i++) {
    solve();
  }
}
