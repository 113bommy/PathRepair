#include<bits/stdc++.h>
using namespace std;
int main(){
  int N,C;
  string S;
  cin >> S;
  N=size(S);
  for(int i=0;i<N;i++){
    if(S[i]=='x')C++;
  }
  if(C<8)cout << "YES" <<endl;
  else cout << "NO" <<endl;
}
