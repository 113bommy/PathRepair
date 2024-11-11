#include<iostream>

using namespace::std;

int main(){
	int n;
 	cin>>n;
  	for(int i=1;i<=9;i++)
      	if(!(n%i) && n/i<=9){
        	cout<<"Yes\n";
          	return 0;
        }
  	cout<<"No\n";
}