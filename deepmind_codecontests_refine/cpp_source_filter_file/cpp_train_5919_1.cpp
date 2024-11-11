#include <bits/stdc++.h>
using namespace std;
int main(){
  int N,S=0,i;cin>>N;int A[N];
  for(i=0;i<N;i++)cin>>A[i];
  i=0;
  while(i<N){
    S++;int j=i+1,x=0;
    while(j<N-1&&(A[j]-[j+1])*x>=0){
      if(A[j]!=A[j+1]){
        if(A[j]>A[j+1])x++;
        else x--;
      }
      j++;
    }
    i=j+1;
  }
  cout<<S<<endl;
}