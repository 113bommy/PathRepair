#include <iostream>
#include<vector>
using namespace std;


int main() {
	int H,W,h,w;cin>>H>>W>>h>>w;
	int minus=(H/h)*(W/w);
	int plus=(H%h)*W+(W%w)*H-(H%h)*(W%w);
//	cout<<minus<<' '<<plus<<endl;
	if((H%h)+(W%w)==0){
		cout<<"No"<<endl;
		return 0;
	}else{
		cout<<"Yes"<<endl;
	}
	int def=1;
	for(int i=0;i<9;i++){
		def*=10;
	}
	for(int i=1;i<=H;i++){
		for(int j=1;j<=W;j++){
			int num=(def/(h*w));
			if((i%h)+(j%w)==0){
				num=-h*w*(def/(h*w))+(def/(h*w))-1;
			}
			cout<<num<<' ';
		}
		cout<<endl;
	}
	return 0;
}
