#include <bits/stdc++.h>
using namespace std;
const int N = 100005, M = 1000000007, BIG = 0x3f3f3f3f;
int ct = 0;
int n;
string s;
bool Read() {
  cin >> n;
  if (cin.eof()) return 0;
  cin >> s;
  return 1;
}
void Process() { cout << s.length() + 1 << "\n"; }
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  while (Read()) Process();
  return 0;
}
