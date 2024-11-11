#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int main(){
	int n,f[100][100],p[100][11];

	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<10,j++)cin>>f[i][j];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<11;j++)cin>>p[i][j];
	}

	int ans=-(1<<30);
	for(int b=0;b<(1<<10);b++){
		int cc=0;
		for(int i=0;i<n;i++){
			int c=0;
			for(int j=0;j<10;j++)
				if(((b>>j))&1&&f[i][j])c++;
			cc+=p[i][c];
		}
		if(ans<cc)ans=cc;
	}
	cout<<ans<<endl;
}