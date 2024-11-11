#include<bits/stdc++.h>
using namespace std;

int main(){
  int N,a,count;
  cin >> N;
 for(int i=1;i<N+1;i++){ 
  cin >> a;
  if(a!=i){
  count++;
  }
 }
  if(count>2){
  cout<<"NO"<<endl;
  }
  else{
  cout<< "YES"<<endl;
  }

}
