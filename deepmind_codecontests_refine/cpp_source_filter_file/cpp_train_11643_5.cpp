#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
  string S;
  cin >> S;
  sort(S.begin(), S.end())
  cout << (S=="abc"?"Yes":"No") << endl;
  return 0;
}