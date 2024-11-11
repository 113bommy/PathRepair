#include <iostream>
using namespace std;

int main(){
	int n,m,l;
	cin >> n >> m >> l;
	
	long long int a[100][100], b[100][100];
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin >> a[i][j];
		}
	}
	for(int i=0; i<m; i++){
		for(int j=0; j<l; j++){
			cin >> b[i][j];
		}
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<l; j++){
			long long int e=0;
			for(int f=0; f<m; f++){
				e += a[i][f]*b[f][j];
			}
			if(j==0) cout << e;
			else cout <<" " << e;
	
		}
		cout<<endl;
	}
	return 0;
}
