#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,L,s=0;
  cin >> N >> L;
  for(int i=0; i<N; i++){
    s+=L+i
  }
  if(L>=0){
    s-=L;
  }
  else if(L<=(-1)*N){
    s-=L+N-1;
  }
  cout << s << endl;
}