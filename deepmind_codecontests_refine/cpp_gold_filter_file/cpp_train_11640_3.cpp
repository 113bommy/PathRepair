#include <bits/stdc++.h>
using namespace std;

int main(){
  int a;
  cin>>a;
  int now;
  cin>>now;
  now--;
  for(int i=0;i<a-1;i++){
	int num;
    cin>>num;
    if(num<now){
      cout<<"No"<<endl;
      return 0;
    }
    else now=max(now,num-1);
  }
  cout<<"Yes"<<endl;
  return 0;
}


