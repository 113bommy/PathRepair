#include<iostream>
using namespace std;

int main()
{
	int i,j,n,u,k,a;
	int v[100][100];
	cin >> n;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			v[i][j]=0;
		}
	}
	for(i=0;i<n;i++){
		cin >> u;
		cin >> k;
		for(j=0;j<k;j++){
			cin >>a;
			v[u-1][a-1]=1;
		}
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			cout << v[i][j];
			if (i!==n-1) cout << " ";
		}
		cout<<endl;
	}
}