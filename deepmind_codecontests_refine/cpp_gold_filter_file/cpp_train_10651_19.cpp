#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, k, j, R1, R2, ii, R3, F[100][3];
  string s, km[100];
  vector<string> Nm[3];
  cin >> n;
  R1 = 0;
  R2 = 0;
  R3 = 0;
  for (i = 1; i <= n; i++) {
    cin >> k >> km[i - 1];
    F[i - 1][0] = 0;
    F[i - 1][1] = 0;
    F[i - 1][2] = 0;
    for (j = 1; j <= k; j++) {
      cin >> s;
      if ((s[0] == s[1]) && (s[0] == s[3]) && (s[0] == s[4]) &&
          (s[0] == s[6]) && (s[0] == s[7]))
        F[i - 1][0]++;
      else if ((s[0] > s[1]) && (s[1] > s[3]) && (s[3] > s[4]) &&
               (s[4] > s[6]) && (s[6] > s[7]))
        F[i - 1][1]++;
      else
        F[i - 1][2]++;
    }
    R1 = max(R1, F[i - 1][0]);
    R2 = max(R2, F[i - 1][1]);
    R3 = max(R3, F[i - 1][2]);
  }
  for (i = 1; i <= n; i++) {
    if (F[i - 1][0] == R1) Nm[0].push_back(km[i - 1]);
    if (F[i - 1][1] == R2) Nm[1].push_back(km[i - 1]);
    if (F[i - 1][2] == R3) Nm[2].push_back(km[i - 1]);
  }
  cout << "If you want to call a taxi, you should call: ";
  for (i = 1; i <= Nm[0].size(); i++) {
    cout << Nm[0][i - 1];
    if (i < Nm[0].size()) cout << ", ";
  }
  cout << "." << endl;
  cout << "If you want to order a pizza, you should call: ";
  for (i = 1; i <= Nm[1].size(); i++) {
    cout << Nm[1][i - 1];
    if (i < Nm[1].size()) cout << ", ";
  }
  cout << "." << endl;
  cout
      << "If you want to go to a cafe with a wonderful girl, you should call: ";
  for (i = 1; i <= Nm[2].size(); i++) {
    cout << Nm[2][i - 1];
    if (i < Nm[2].size()) cout << ", ";
  }
  cout << "." << endl;
  return 0;
}
