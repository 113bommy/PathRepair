#include <bits/stdc++.h>
using namespace std;
int main() {
  string s1, s2, s3;
  cin >> s1 >> s2 >> s3;
  int a1, a2, a3;
  if (s1 == "rock") a1 = 1;
  if (s1 == "scissors") a1 = 2;
  if (s1 == "paper") a1 = 3;
  if (s2 == "rock") a2 = 1;
  if (s2 == "scissors") a2 = 2;
  if (s2 == "paper") a2 = 3;
  if (s3 == "rock") a3 = 1;
  if (s3 == "scissors") a3 = 2;
  if (s3 == "paper") a3 = 3;
  if (a1 == 1 && a2 == 2 && a3 == 2) cout << "F", exit(0);
  if (a1 == 2 && a2 == 3 && a3 == 3) cout << "F", exit(0);
  if (a1 == 3 && a2 == 1 && a3 == 1) cout << "F", exit(0);
  if (a2 == 1 && a1 == 2 && a3 == 2) cout << "M", exit(0);
  if (a2 == 2 && a1 == 3 && a3 == 3) cout << "M", exit(0);
  if (a2 == 3 && a1 == 1 && a3 == 1) cout << "M", exit(0);
  if (a3 == 1 && a1 == 2 && a2 == 2) cout << "S", exit(0);
  if (a3 == 2 && a1 == 3 && a2 == 3) cout << "S", exit(0);
  if (a3 == 3 && a1 == 1 && a2 == 1) cout << "S", exit(0);
  cout << "?";
  return 0;
}
