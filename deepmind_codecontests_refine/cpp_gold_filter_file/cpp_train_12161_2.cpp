#include<iostream>
#include<vector>
using namespace std;

int main(){
	int N,M,C,ans=0,d,e;
  	
  	cin >> N >> M >> C;
  	vector<int> B(M,0);
  	for(int j=0;j<M;j++)cin >> B[j];
  	for(int i=0;i<N;i++){
      	d=C;
    	for(int j=0;j<M;j++){
          cin >> e;
          d+=e*B[j];
        }
    	if(d>0)ans++;
    }
  	cout << ans;
}
