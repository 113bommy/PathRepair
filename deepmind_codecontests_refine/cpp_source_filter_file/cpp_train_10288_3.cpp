#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main(){
	int n;
	cin >> n;
	int x[100],y[100],h[100];
	for(int i=0;i<n;i++){
		cin >> x[i] >> y[i] >> h[i];
	}
	int x1,y1,h1,x2,y2,h2,m,j;
	for(j=0;j<10201||m==n;j++){
		x1=j/101;
		y1=j%101;
		m=0;
		for(int l=0;l<n;l++){
			if(!(h[l]==0){
				h1=h[l]+abs(x1-x[l])+abs(y1-y[l]);
			}
		for(int k=0;k<n;k++){
			if(h[k]==max(h1-abs(x1-x[k])-abs(y1-y[k]),0)&&h1>=h[k]&&h1>0){
				m++;
			}
		}
		if(m==n){
			x2=x1;
			y2=y1;
			h2=h1;
		}
	}
	cout << x2 << " " << y2 << " " << h2 << endl;
	return 0;
}
