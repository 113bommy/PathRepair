#include<iostream>
#include<cstdlib>
using namespace std;

int main(){
	while(1){
		int n;
		cin>>n;
		if(n==0)
			break:
		int a[1000];
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		int s=1000001;
		for(int i=0;i<n;i++){
			for(int j=0;j<n-1;j++){
				if(s>abs(a[i]-a[j])){
					s=abs(a[i]-a[j]);
				}
			}
		}
		cout<<s<<endl;
	}
	return 0;
}