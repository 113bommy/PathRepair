#include <iostream>
using namespace std;
int seihin[300];int test[1000][4];
int a,b,c,n;
bool henka
 
void check(){
	for(int i=0;i<n;i++){
		int p=0;int k;
		if(test[i][3] == 0){
		for(int j =0;j<=2;j++){
			if(seihin[test[i][j]-1]!=1){
				k=test[i][j]-1;
				p++;}
		}
		if(p==1 and seihin[k]==2){
			henka=true;
			seihin[k]=0;
		}
		}
	}
}
 
int main() {
while(1){
	henka=true;
for(int i = 0;i<300;i++){
	seihin[i]=2;
}
cin>>a>>b>>c;
if(a==0 and b==0 and c==0){break;}
cin>>n;
int y=a+b+c;
for(int i=0;i<n;i++){
	cin>>test[i][0]>>test[i][1]>>test[i][2]>>test[i][3];
}
for(int i = 0;i<n;i++){
	if(test[i][3]==1){
		for(int j=0;j<=2;j++){
			seihin[test[i][j]-1]=1;
		}
	}
}
 
while(henka==true){
	henka=false;
	check();
}
for(int i=0;i<y;i++){
	cout<<seihin[i]<<endl;
}
}
	return 0;
}