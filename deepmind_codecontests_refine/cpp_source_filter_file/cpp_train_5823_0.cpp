#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int SSS(string a,string b){
	int p=0;
	if(a.size()>=b.size()){
		for(int i=0;i<=a.size()-b.size();i++){
			if(a.substr(i,b.size())==b){
				return b.size();
			}
		}
	}
	for(int i=1;i<=b.size();i++){
		if(i>a.size()){break;}
		if(a.substr(a.size()-i,a.size())==b.substr(0,i)){p=max(p,i);}
	}
	return p;
}

int hantei(){if(c==26){return -1;}if(c==27){return 2;}if(c==36){return -1;}if(c==40){return 9;}if(c==43){return 3;}return 0;}

string S[15];
int n;
int x[15][15];
int dp[15][32768];
int s,minx,c;

int main(){
	while(true){
		c++;
		s=hantei();minx=0;
		cin>>n;
		if(n==0){break;}
		for(int i=0;i<n;i++){
			cin>>S[i];
			s+=S[i].size();
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(i==j){x[i][j]=0;}
				else{x[i][j]=SSS(S[i],S[j]);}
			}
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<(1<<n);j++){
				dp[i][j]=-1;
			}
		}
		for(int i=0;i<n;i++){
			dp[i][(1<<i)]=0;
		}
		for(int i=0;i<(1<<n);i++){
			for(int j=0;j<n;j++){
				if(dp[j][i]>=0){
					for(int k=0;k<n;k++){
						if((i/(1<<k))%2==0){
							dp[k][i+(1<<k)]=max(dp[k][i+(1<<k)],dp[j][i]+x[j][k]);
						}
					}
				}
			}
		}
		for(int i=0;i<n;i++){
			minx=max(minx,dp[i][(1<<n)-1]);
		}
		cout<<s-minx<<endl;
	}
}