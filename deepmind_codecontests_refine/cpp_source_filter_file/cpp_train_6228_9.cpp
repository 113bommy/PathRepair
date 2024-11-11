#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N,M,X,Y;
  cin >>N>>M>>X>>Y;
  int max = X;
  int min = Y;
  for(int i=0;i<N;i++){
    int a_i;
    cin >>a_i;
    max = max(max,a_i);
  }
  for(int i=0;i<M;i++){
    int b_i;
    cin >>b_i;
    min = min(min,b_i);
  }
  if(max<min) cout <<"No War" << endl;
  else cout << "War" << endl;
}