#include <iostream>
using namespace std;
int main(){
	int a,b,c;
	cin>>a>>b>>c;
	if (a>=c) cout<<0<<endl;
	else if (a+b<c) cout<<"NA"<<endl;
	else cout<<c-a<<endl;
	return 0;
}