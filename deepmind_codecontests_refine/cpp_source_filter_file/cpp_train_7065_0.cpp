#include<iostream>
#include<cstring>
using namespace std;

int main(){
  int num,a[4]={};
  char c;
  string s,b[4]={"A","B","AB","O"};

  while(cin>>num>>c>>s){
      if(s==b[0]) 
	a[0]++;
      else if(s==b[1]) 
	a[1]++;
      else if(s==b[2]) 
	a[2]++;
      else a[3]++;
  }
  for(int i=0;i<4;i++)
    cout<<a[i]<<endl;
 return 0;