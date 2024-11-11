#include<iostream>
using namespace std;
int main(){
	int N;
	int x[1009],y[1009];
	int h[1009];
	cin>>N;
	for(int i=0;i<N;i++)cin>>x[i]>>y[i]>>h[i];
	for(int i=0;i<=100;i++){
		for(int j=0;j<=100;j++){
			int H;
			for(int k=0;k<N;k++){
				if(h[k]>0)H=h[k]+abs(x[k]-i)+abs(y[k]-j);
			}
			bool flag=true;
			for(int k=0;k<N;k++){
			   	if(h[k]!=max(H-abs(x[k]-i)-abs(y[k]-j),0))flag=false;
			}
			if(flag==true){
				cout<<i<<" "<<j<<" "<<H<<endl;
				return 0;
			}
		}
	}
}