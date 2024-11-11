#include <bits/stdc++.h>
using namespace std;

int main(){
  char a,c[128];
  cin >> a;
  c['A'] = 'T';
  c['T'] = 'A';
  c['C'] = 'G';
  c['G'] = 'C';
  cout << c[(int)a] << endl;
}
