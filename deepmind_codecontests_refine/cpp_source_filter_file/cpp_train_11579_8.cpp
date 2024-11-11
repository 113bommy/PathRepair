#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cout.tie(0);
  cin.tie(0);
  cout << "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
          "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
          "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
          "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
          "aaaaaaaaaaaaaaaaaaaaaaaaaaaa\n";
  cout.flush();
  int A;
  cin >> A;
  if (A == 0) exit(0);
  A = 300 - A;
  cout << "bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb"
          "bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb"
          "bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb"
          "bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb"
          "bbbbbbbbbbbbbbbbbbbbbbbbbbbb\n";
  cout.flush();
  int B;
  cin >> B;
  if (B == 0) exit(0);
  B = 300 - B;
  string guess = "";
  A += B;
  for (int i = 0; i < A; i++) guess += 'a';
  for (int i = 1; i < A; i++) {
    guess[i] = 'b';
    cout << guess << '\n';
    cout.flush();
    int wow;
    cin >> wow;
    if (wow < B)
      B = wow;
    else
      guess[i] = 'a';
    if (B == 0) exit(0);
  }
  if (B == 1) guess[0] = 'b';
  cout << guess << '\n';
  cout.flush();
  cin >> B;
  exit(0);
}
