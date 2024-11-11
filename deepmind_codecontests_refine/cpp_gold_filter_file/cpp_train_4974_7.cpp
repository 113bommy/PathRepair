#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int De;
  cin>>De;
  vector<vector<int>> vec(De, vector<int>(26));
  vector<int>ve(De);
  for(int X=0;X<De;X++){
    cin>>ve.at(X);
  }
  for (int i = 0; i < De; i++) {
    for (int j = 0; j < 26; j++) {
      cin>>vec.at(i).at(j);
    }
  }
  for(int X=0;X<De;X++){
    cout<<1<<endl;
  }
}
