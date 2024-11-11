#include <iostream>
using namespace std;
 
int main() {
	int n;
  char a;
  cin>>n;
  int ans=0;
for(int i=0;i<n;i++){
  cin>>a;
  if(a=='Y')ans=1;
  }
  
  if(ans)cout<<"Four";
  else{cout<<"Three";}
}