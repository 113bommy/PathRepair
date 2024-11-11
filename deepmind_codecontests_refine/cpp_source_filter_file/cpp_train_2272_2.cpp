#include <iostream>
#include <algorithm>

using namespace std;

long long d[40][40],z[510][510],a[40][3];
int main(){
	int n,c,i,j,k,ans;
	cin >> n >> c;
	for(i=1;i<=c;i++){
		for(j=1;j<=c;j++){
			cin >> d[i][j];
		}
	}
	
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			cin >> z[i][j];
		}
	}
	
	ans = 9000000000000;
	
	for(k=1;k<=c;k++){
		a[k][0]=0;
		a[k][1]=0;
		a[k][2]=0;
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				if((i+j)%3==0){
					a[k][0] += d[z[i][j]][k];
				}
				if((i+j)%3==1){
					a[k][1] += d[z[i][j]][k];
				}
				if((i+j)%3==2){
					a[k][2] += d[z[i][j]][k];
				}
			}
		}
	}
	
	for(i=1;i<=c;i++){
			for(j=1;j<=c;j++){
				if(i!=j){
					for(k=1;k<=c;k++){
						if(i!=k && j!=k){
							ans = min(ans,a[i][0]+a[j][1]+a[k][2]);
						}
					}
				}
			}
	}
	cout << ans << endl;
}
						
		