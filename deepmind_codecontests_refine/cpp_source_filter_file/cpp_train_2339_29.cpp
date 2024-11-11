#include <bits/stdc++.h>
using namespace std;
map<string, string> A;
int main() {
  A["rock"] = "scissors";
  A["scissors"] = "paper";
  A["paper"] = "rock";
  string a, b, c, kq = "?";
  cin >> a >> b >> c;
  if (A[a] == b && A[a] == c) kq = "F";
  if (A[b] == a && A[b] == c) kq = "M";
  if (A[c] == b && A[c] == a) kq = "F";
  cout << kq;
}
