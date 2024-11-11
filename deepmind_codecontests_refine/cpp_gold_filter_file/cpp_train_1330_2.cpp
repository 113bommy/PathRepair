#include <bits/stdc++.h>
using namespace std;
int main(){
int N;
cin>>N;
 int S =N%10;
  if(S==3){
  	cout<<"bon";
  }
  else if(S==1 ||S==6 || S==8 || S==0){
  cout<<"pon";
  }
  else{
  cout<<"hon";
  }
}