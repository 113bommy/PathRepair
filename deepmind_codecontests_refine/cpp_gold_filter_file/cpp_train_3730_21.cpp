#include <bits/stdc++.h>
using namespace std;
int main(){
  string a;
  cin >> a;
  cout << count(a.begin(), a.end(), 'o') * 100 + 700 << endl;
  return 0;
}