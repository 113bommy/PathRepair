#include <iostream>
#include <utility>
#include <algorithm>

using namespace std;

int i,j,n,x[510],a[300000],b[300000],y[510];
pair<int,int> p[510];
int main(){
	cin >> n;
	for(i=1;i<=n;i++){
		cin >> x[i];
		a[x[i]] = i;
		b[x[i]] = 1;
		y[i]=n-i;
		p[i]=make_pair(x[i],i);
	}
	
	for(i=1;i<=n*n;i++){
		if(b[i]==1){
			int cnt = a[i]-1;
			for(j=1;j<=i;j++){
				if(cnt==0){
					break;
				}
				if(b[j]==0){
					a[j] = a[i];
					b[j] = 1;
					cnt--;
				}
				if(j==i){
					cout << "No" << endl;
					return 0;
				}
			}
		}
	}
	sort(p,p+n);
	for(i=1;i<=n*n;i++){
		if(b[i]==0){
			for(j=1;j<=n;j++){
				if(y[p[j].second]!=0){
					y[p[j].second]--;
					a[i]=p[j].second;
					b[i]=1;
					break;
				}
			}
		}
	}
	for(i=1;i<=n*n;i++){
		b[i]=0;
	}
	for(i=1;i<=n*n;i++){
		b[a[i]]++;
		if(b[a[i]]==a[i]){
			if(i!=x[a[i]]){
				cout << "No" << endl;
				return 0;
			}
		}
	}
	
	cout << "Yes" << endl;
	for(i=1;i<=n*n;i++){
		cout << a[i] << " ";
	}
	cout << endl;
}
	