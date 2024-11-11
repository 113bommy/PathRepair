#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin>> N;
  int sum =0;
  
  for(int i=N; i!=0 ;i/=10){
    sum+= i%10 ;
  }
  if(N%sum==0)cout<< "Yes";
  else cout<< "No";
}
