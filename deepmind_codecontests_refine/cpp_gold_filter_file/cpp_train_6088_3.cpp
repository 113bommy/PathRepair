#include <bits/stdc++.h>
using namespace std;
map<string, int> m;
int main() {
  int i, n, j, mx = -1000;
  cin >> n;
  string S1, S2, S3;
  m["polycarp"] = 1;
  for (i = 0; i < n; i++) {
    cin >> S1 >> S2 >> S3;
    for (j = 0; j < S1.size(); j++) S1[j] = tolower(S1[j]);
    for (j = 0; j < S3.size(); j++) S3[j] = tolower(S3[j]);
    m[S1] = m[S3] + 1;
    if (m[S1] > mx) mx = m[S1];
  }
  cout << mx << endl;
}
