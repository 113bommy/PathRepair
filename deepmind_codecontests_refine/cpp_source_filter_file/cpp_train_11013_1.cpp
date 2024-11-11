#include <iostream>
using namespace std;
int a[100002];
int main(){
	int n,k,q;
	cin>>n>>k>>q;
	for(int i=1;i<=q;i++){
		int p;
		cin>>p;
		a[p]++;
	}
	for(int i=1;i<=n;i++){
		if(a[i]+p-q>0){
			cout<<"Yes"<<endl;
		}else{
			cout<<"No"<<endl;
		}
	}
} 