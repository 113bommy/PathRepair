#include <iostream>
#include <algorithm>
using namespace std;
int N,A,B,C[3],P;
int main(){
  cin>>N>>A>>B;
  for(int i=0;i<N;i++){
    cin>>P;
    if(P<=A){C[0]++;}
    else if(P<=B){C[1]++;}
    else{C[2]++;}
  }
  cout<<min(C[0],C[1],C[2])<<endl;
}