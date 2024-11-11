#include<iostream>
using namespace std
int main(){
  int n,x[100],i,j,min=100000000,sum=0;
  cin >> n;
  for(i=0; i<n; i++){
    cin >> x[i];
  }
  for(i=1; i<100; i++){
    sum=0;
    for(j=0; j<n; j++){
      sum+=(x[j]-i)*(x[j]-i);
    }
    if(sum<min){
      min=sum;
    }
  }
  cout << min << endl;
 
}