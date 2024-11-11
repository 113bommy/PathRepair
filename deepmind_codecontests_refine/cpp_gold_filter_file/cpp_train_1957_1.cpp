#include<bits/stdc++.h>
using namespace std;
int main(){
  int N;
  string S;
  cin >> N >> S;
  for(int i=0; i<S.size(); i++){
    cout << char('A'+(S[i]+N+'A')%26);
  }
  cout<<endl;
}
