#include<iostream>
using namespace std;

int main(){
 int N,D[100],a;
  int i,j;
  cin>>N;
  for(i=0;i<N;i++){
    cin>>D[i];
  }
  for(j=0;j<N-1;j++){
   for(i=j+1;i<N;i++){
     a +=D[j]*D[i];
   }
  }
  cout<<a<<endl;
}