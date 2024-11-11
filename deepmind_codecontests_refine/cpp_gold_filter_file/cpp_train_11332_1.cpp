#define rep(i,n) for (int i=0;i<(n);i++)
#include<iostream>
using namespace std;

int main(){
	int m,n;
	string a[51],b[51];
	cin >> n >> m;
	rep(i,n) cin >>a[i];
	rep(i,m) cin >>b[i];

	bool exist = false;
	for(int i=0;i<=n-m;i++){
		for(int j=0;j<=n-m;j++){
				bool match = true;
				for(int y=0;y<m;y++){
					for(int x=0;x<m;x++){
						if(a[i+y][j+x]!=b[y][x]) match=false;
						continue;
					}
				}
				if(match) exist=true;
		}
	}

	cout << ((exist) ? "Yes\n":"No\n");
	return 0;
}