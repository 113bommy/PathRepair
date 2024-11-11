#include <bits/stdc++.h>
using namespace std;

int main(){
	int i,n,a,b,p[101],c1=0,c2=0,c3=0;
  	cin>>n>>a>>b;
  	for(i=0;i<n;i++){
	cin>>p[i];
      if(p[i]<=a){
		c1++;
      }else if(p[i]>b){
		c3++;
      }else{
		c2++;
      }
    }
  
  	cout << std::min{c1,c2,c3} << endl;
}
  	
