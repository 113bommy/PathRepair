#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N,M,X,Y;
  cin >>N>>M>>X>>Y;
  int ma = X;
  int mi = Y;
  for(int i=0;i<N;i++){
    int a_i;
    cin >>a_i;
    ma = max(ma,a_i);
  }
  for(int i=0;i<M;i++){
    int b_i;
    cin >>b_i;
    mi = min(mi,b_i);
  }
  if(ma<mi) cout <<"No War" << endl;
  else cout << "War" << endl;
}