#include<bits/stdc++.h>
using namespace std;
int a[4][4],n,b;
bool f[4][4];
int main(){
	for(int i=1;i<=3;i++)
		for(int j=1;j<=3;j++)
			cin>>a[i][j];
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>b;
		for(int j=1;j<=3;j++)
			for(int k=1;k<=3;k++){
				if(b==a[j][k])
					f[j][k]=true;
			}
	}
	if((f[1][1]&&f[1][2]&&f[1][3])||(f[2][1]&&f[2][2]&&f[2][3])||(f[3][1]&&f[3][2]&&f[3][3])||(f[1][1]&&f[2][1]&&f[3][1])||(f[1][2]&&f[2][2]&&f[3][2])||(f[1][3]&&f[2][3]&&f[3][3])||(f[1][1]&&f[2][2]&&f[3][3])||(f[1][3]&&f[2][2]&&f[3][1]))
		cout<<"Yes"<<endl;
	else
		cout<<"No"<<endl; 
	return 0;
} 