#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;
  string S;
  cin >> N >> S;
  vector<int> C(26);
  for(int i=0; i<N; i++){
    C.at(S.at(i)-'a')++;
  }
  int64_t Ans=1;
  for(int i=0; i<26; i++){
    Ans*=C.at(i)+1;
    Ans%=1000000007
  }
  cout << Ans-1 << endl;
}