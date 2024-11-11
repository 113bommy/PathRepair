#include <iostream>
using namespace std;

int main(){
	int a,b,c,n,t;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a>>b>>c;
		if(a<b){
			t=a;
			a=b;
			b=t;
		}
		if(a<c){
			t=a;
			a=c;
			c=t;
		}
		cout<<a*a==b*b+c*c ? "YES\n" : "NO\n";
	}
	return 0;
}