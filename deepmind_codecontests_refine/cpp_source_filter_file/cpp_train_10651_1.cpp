#include <bits/stdc++.h>
using namespace std;
int main() {
  int N, n, i, j, k, max[3];
  cin >> N;
  int ar[3][N];
  bool flag = 0;
  string s[N];
  for (i = 0; i < 3; i++) {
    for (j = 0; j < N; j++) ar[i][j] = 0;
  }
  for (i = 0; i < N; i++) {
    cin >> n;
    getchar();
    cin >> s[i];
    string S[n];
    for (j = 0; j < n; j++) {
      cin >> S[j];
      if (S[j][1] == S[j][0] && S[j][4] == S[j][3] && S[j][7] == S[j][6] &&
          S[j][6] == S[j][4] && S[j][3] == S[j][1])
        ar[0][i]++;
      else if (S[j][1] < S[j][0] && S[j][4] < S[j][3] && S[j][7] < S[j][6] &&
               S[j][6] < S[j][4] && S[j][3] < S[j][1])
        ar[1][i]++;
      else
        ar[2][i]++;
    }
  }
  for (i = 0; i < 3; i++) {
    max[i] = *max_element(ar[i], ar[i] + N);
  }
  cout << "If you want to call a taxi, you should call: ";
  for (i = 0; i < N; i++) {
    if (ar[0][i] == max[0]) {
      if (flag == 0) {
        flag = 1;
        cout << s[i];
      } else
        cout << "," << s[i];
    }
  }
  cout << ".";
  cout << endl;
  cout << "If you want to order a pizza, you should call: ";
  flag = 0;
  for (i = 0; i < N; i++) {
    if (ar[1][i] == max[1]) {
      if (flag == 0) {
        flag = 1;
        cout << s[i];
      } else
        cout << "," << s[i];
    }
  }
  cout << ".";
  cout << endl;
  cout
      << "If you want to go to a cafe with a wonderful girl, you should call: ";
  flag = 0;
  for (i = 0; i < N; i++) {
    if (ar[2][i] == max[2]) {
      if (flag == 0) {
        flag = 1;
        cout << s[i];
      } else
        cout << "," << s[i];
    }
  }
  cout << ".";
  return 0;
}
