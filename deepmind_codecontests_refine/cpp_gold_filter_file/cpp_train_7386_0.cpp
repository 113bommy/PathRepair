#include<iostream>
#include<algorithm>
using namespace std;
char  ta[50][50],tb[50][50];
	int n,h,w;
	bool used[50][50],can[50][50];
	bool ok(){

		for(int i=0;i<h;i++){
			for(int j=0;j<w;j++){
			tb[i][j]=ta[i][j];
			}
		}
		
		int cnt=0;
		char tmp;
		bool endf=0;
		for(int cc=0;cc<300;cc++){
			endf=0;
			for(int i=0;i<50;i++)for(int j=0;j<50;j++)used[i][j]=0,can[i][j]=0;
			for(int i=0;i<h;i++)for(int j=0;j<w;j++)if(tb[i][j]!='.')can[i][j]=1;
				//
			for(int i=h-1;i>=0;i--){
				for(int j=w-1;j>=0;j--){
					int ni=i;
					if(tb[i][j]!='.'){
						while(1){
							if(ni+1>=h||tb[ni+1][j]!='.'||can[i][j]==0)break;
							tb[ni+1][j]=tb[ni][j];
							tb[ni][j]='.';
							ni++;
						}
					}
				}
			}
			//if(cc==0)for(int i=0;i<h;i++){for(int j=0;j<w;j++){cout<<tb[i][j];}cout<<endl;}
		
		
		

		for(int i=0;i<h;i++){
			for(int j=0;j<w;j++){
				cnt=0;
				tmp=tb[i][j];
					while(j<w&&tb[i][j+cnt]==tmp&&tmp!='.')cnt++;
				if(cnt>=n){
					for(int nj=j;nj<j+cnt;nj++)used[i][nj]=1,endf=1;
				}
			}
		}
		
			for(int i=0;i<h;i++){
			for(int j=0;j<w;j++){
				cnt=0;
				tmp=tb[i][j];
					while(i<h&&tb[i+cnt][j]==tmp&&tmp!='.')cnt++;
				if(cnt>=n){
					for(int ni=i;ni<i+cnt;ni++)used[ni][j]=1,endf=1;
				}
			}
		}
		for(int i=0;i<h;i++){
			for(int j=0;j<w;j++){
				if(used[i][j])tb[i][j]='.';
			}
		}
			if(endf==0)break;
		}
		bool nf=1;
		//for(int i=0;i<h;i++){for(int j=0;j<w;j++){cout<<tb[i][j];}cout<<endl;}
		//cout<<endl;
		for(int i=0;i<h;i++)for(int j=0;j<w;j++)if(tb[i][j]!='.')nf=0;
		return nf;
	}
int main(){

	cin>>h>>w>>n;
	
	bool f=0;
	for(int i=0;i<h;i++)for(int j=0;j<w;j++)cin>>ta[i][j];

	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			for(int ii=0;ii<h;ii++)for(int jj=0;jj<w;jj++)can[ii][jj]=0;
			//cout<<i<<" "<<j<<endl;
			/*if(i+1<h){
				swap(ta[i][j],ta[i+1][j]);
				can[i][j]=can[i+1][j]=1;
				if(ok())f=1;
				swap(ta[i][j],ta[i+1][j]);
			}*/
			for(int ii=0;ii<h;ii++)for(int jj=0;jj<w;jj++)can[ii][jj]=0;
			if(j+1<w){
				swap(ta[i][j],ta[i][j+1]);
				if(ok())f=1;
				swap(ta[i][j],ta[i][j+1]);
			}
		}
	}
	if(f)cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	return 0;
}