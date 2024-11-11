#include<bits//stdc++.h>
using namespace std;
int main(){
	int n;
	while(cin>>n&&n!=0){
		int a,b;
		int ma=-1111111,mi=1000000;
		for(int i=0;i<n;i++){
			b=0;
			for(int j=0;j<5;j++) {
				cin>>a;
				b+=a;
			}
			ma=max(b,ma);
			mi=min(b,mi);
		}
		cout<<ma<<" "<<mi<<endl;
	}
}