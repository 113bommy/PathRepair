#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  map<string, int> MA;
  string S;
  while (cin >> S) MA[S]++;
  for (auto s : {"AC", "WA", "TLE", "RE"}) cout << s << " x " << MA[s] << "\n";
}