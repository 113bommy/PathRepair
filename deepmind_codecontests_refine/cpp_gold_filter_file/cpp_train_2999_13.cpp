#include <bits/stdc++.h>
#include <cmath>
#include <iostream>

using namespace std;

int main() {
  string S;
  cin>>S;
  sort(S.begin(),S.end());
  if(S[0]==S[1] && S[2]==S[3] && S[1]!=S[2]) cout<<"Yes";
  else cout<<"No";
}
