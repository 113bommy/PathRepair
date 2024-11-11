#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  int L=0,U=1000,x;
  for(int i=0;i<N;i++){
    cin >> x;
    L=max(L,x);
    U=min(U,x);
  }
  cout << L-U;
}
