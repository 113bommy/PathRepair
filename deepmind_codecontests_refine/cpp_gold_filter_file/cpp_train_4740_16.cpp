#include <bits/stdc++.h>
using namespace std;
static const double EPS = 1e-5;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
pair<int, int> guess(string& cor, string& gu) {
  set<char> app;
  for (int i = 0; i < (int)4; ++i) app.insert(cor[i]);
  int b = 0, c = 0;
  for (int i = 0; i < (int)4; ++i) {
    if (cor[i] == gu[i]) ++b;
    if (app.count(gu[i])) ++c;
  }
  return make_pair(b, c - b);
}
int main() {
  char per[10];
  for (int i = 0; i < (int)10; ++i) per[i] = i + '0';
  sort(per, per + 10);
  int n;
  cin >> n;
  string in[n];
  int b[n], c[n];
  for (int i = 0; i < (int)n; ++i) cin >> in[i] >> b[i] >> c[i];
  string ans;
  for (int i = 0; i < (int)10; ++i) {
    for (int j = 0; j < (int)i; ++j) {
      for (int k = 0; k < (int)j; ++k) {
        for (int l = 0; l < (int)k; ++l) {
          string ss;
          ss += l + '0';
          ss += k + '0';
          ss += j + '0';
          ss += i + '0';
          do {
            bool ok = true;
            for (int m = 0; m < (int)n; ++m) {
              if (make_pair(b[m], c[m]) != guess(ss, in[m])) {
                ok = false;
                break;
              }
            }
            if (ok) {
              if (ans != "") {
                cout << "Need more data" << endl;
                return 0;
              }
              ans = ss;
            }
          } while (next_permutation((ss).begin(), (ss).end()));
        }
      }
    }
  }
  if (ans == "") {
    cout << "Incorrect data" << endl;
  } else
    cout << ans << endl;
}
