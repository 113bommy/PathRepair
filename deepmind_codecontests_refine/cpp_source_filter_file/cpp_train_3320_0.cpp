#include <iostream>
using namespace std;

int d[300000];

int main(){
	int n,m=1;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>d[i];
	for(int i=1;i<=n;i++){
		if(m < i){
			cout << "no" << endl;
			return 0;
		}
		if(d[i]>=10){
			m=max(i+d[i]/10,m);
		}
	}
	//d[i]を反転させる処理
	for(int i=1;i<=n/2;i++)swap(d[i],d[n+1-i];
	m = 1;
	for(int i=1;i<=n;i++){
		if(m < i){
			cout << "no" << endl;
			return 0;
		}
		if(d[i]>=10){
			m=max(i+d[i]/10,m);
		}
	}
	
	cout << "yes" << endl;


	return 0;

}
