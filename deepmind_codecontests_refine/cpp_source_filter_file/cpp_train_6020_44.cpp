#include <iostream>
using namespace std;

int main(){
	string s;cin>>s;
  	for(auto&& u:s)if(u=='1'){cout<<'9';else cout<<'1';}
	cout<<endl;
}