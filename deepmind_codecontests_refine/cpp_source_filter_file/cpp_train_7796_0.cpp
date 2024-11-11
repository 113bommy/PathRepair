#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int a,b,c,n,flag=1;
	while(1){
		cin>>a>>b>>c;
		if(a==0 && b==0 && c==0)
		break;
		cin>>n;
		int p=0,w[n],x[n],y[n],z[n],ans[a+b+c+1];
		for(int i=0;i<a+b+c+1;i++)
			ans[i]=2;
		for(int i=0;i<n;i++){
			cin>>w[i]>>x[i]>>y[i]>>z[i];
			if(z[i]==1){
				ans[w[i]]==1;
				ans[x[i]]==1;
				ans[y[y]]==1;
			}
		}
		for(int i=0;i<n;i++){
			if(z[i]==0){
				if(ans[w[i]]==1 && ans[x[i]]==1 && ans[y[i]]==2)
				ans[y[i]]=0;
				if(ans[w[i]]==1 && ans[x[i]]==2 && ans[y[i]]==1)
				ans[x[i]]=0;
				if(ans[w[i]]==2 && ans[x[i]]==1 && ans[y[i]]==1)
				ans[w[i]]=0;
			}
		}
		for(int i=1;i<=a+b+c;i++)
		cout<<ans[i]<<endl;
		}
	return 0;
}