c#include<iostream>
using namespace std;

int main(){
  int a,b;
  cin>>a,b;
  int N;
  cin>>N;
  int s,f;
  for(int i=0;i<N;i++){
    cin>>s>>f;
    if(a<f && b>s){
      cout<<1<<endl;
      return 0;
    }
    else if(a==s&&b==f){
      cout<<1<<endl;
      return 0;
    }
  }
  cout<<0<<endl;
  return 0;
}

