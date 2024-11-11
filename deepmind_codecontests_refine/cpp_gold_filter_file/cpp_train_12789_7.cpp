#include <iostream>
using namespace std;
int main(){
	string a,b,c;
	cin>>a>>b;
	for(int i=0;i<b.size();i++){
		c+=a[i];
		c+=b[i];
		}
	
	if(a.size()>b.size()){
			c+=a[a.size()-1];
		}
	cout<<c<<endl;
	return 0;	
}