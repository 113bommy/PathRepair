#include <iostream>
#include <cmath>
#define INF 1e+9
using namespace std;
 
int main(){
	int n,m,a[50],b[50],c[50],d[50];
	cin >> n >> m;
	for(int i = 0;i < n;i++){
		cin >> a[i] >> b[i];
	}
	for(int i = 0;i < m;i++) cin >> c[i] >> d[i];
	for(int i = 0;i < n;i++){
		int mi = INF,mii;
		for(int j = 0;j < m;j++){
			int e = abs(a[i] - c[j]) + abs(b[i] - d[j]);
			if(mi > e){
				mi = e;
				mii = j + 1;
			}
		}
		cout << mii << endl;
	}
	return 0;
}