#include <bits/stdc++.h>
using namespace std;
string S, T;
int x, y, q, w, t, k, r, s;
char A[500005];
int B[500005];
vector<char> X;
bool e;
int main() {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> S >> T;
  for (int i = 0; i < (int)S.size(); i++)
    if (S[i] == 1)
      x++;
    else
      y++;
  for (int i = 0; i < (int)T.size(); i++)
    if (T[i] == 1)
      q++;
    else
      w++;
  t = T.size();
  for (int i = 0; i < t; i++) A[i] = T[i];
  for (int i = 1; i < t; i++) {
    while (A[i] != A[k] && k > 0) k = B[k - 1];
    if (A[i] == A[k]) {
      B[i] = k + 1;
      k++;
    } else {
      B[i] = 0;
    }
  }
  e = true;
  for (int i = 0; i < B[t - 1]; i++)
    if (A[i] == 1)
      r++;
    else
      s++;
  while (1) {
    if (e) {
      if (x >= q && y >= w) {
        for (int i = 0; i < t; i++) X.push_back(A[i]);
        x -= q;
        y -= w;
      } else {
        cout << S;
        return 0;
      }
      e = false;
    } else {
      if (x >= q - r && y >= w - s) {
        for (int i = B[t - 1]; i < t; i++) X.push_back(A[i]);
        x -= (q - r);
        y -= (w - s);
      } else {
        for (int i = 0; i < x; i++) X.push_back('1');
        for (int i = 0; i < y; i++) X.push_back('0');
        break;
      }
    }
  }
  for (int i = 0; i < (int)X.size(); i++) cout << X[i];
  return 0;
}
