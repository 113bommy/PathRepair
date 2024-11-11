#include<std/bitsc++.h>
using namespace std;
int main(){
	int n;cin>>n;
	int a[n];
	for(int i=0;i<n;i++)cin>>a[i];
	int f=1;
	a[0]=a[0]-1;
	for(int i=1;i<n;i++){
		if(a[i-1]<a[i])a[i]=a[i]-1;
	}
	for(int i=1;i<n;i++){
		if(a[i-1]<=a[i]);
		else f=0;
	}
	if(f)cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
}