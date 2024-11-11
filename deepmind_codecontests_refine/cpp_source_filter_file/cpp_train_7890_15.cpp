#include <bits/stdc++.h>
using namespace std;

int main(){
int N;string S;int K;
cin >>N;cin >>S;cin >>K;

for (int i = 0; i < N-1; i++) {
  if(S.at(i)!=S.at(K)){
  S.at(i)="*";
   }
  }
cout << S<< endl;
}