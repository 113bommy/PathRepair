#include <bits/stdc++.h>
using namespace std;
int main() {
  char a, c[128];
  cin >> a;
  c['A'] = 'G';
  c['G'] = 'A';
  c['C'] = 'T';
  c['T'] = 'C';
  cout << c[(int)a] << endl;
}
