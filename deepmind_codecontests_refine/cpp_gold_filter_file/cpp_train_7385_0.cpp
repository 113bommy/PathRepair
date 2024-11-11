#include<string>
#include<iostream>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

string LCS(const string &s,const string &t){
	const int LMAX=300;
	int m=s.length(),n=t.length();
	static int dp[LMAX+1][LMAX+1],from[LMAX+1][LMAX+1];

	rep(i,m+1) dp[i][0]=0, from[i][0]=-1;
	rep(j,n+1) dp[0][j]=0, from[0][j]=-1;

	rep(i,m) rep(j,n) {
		if(s[i]==t[j]){
			dp[i+1][j+1]=dp[i][j]+1;
			from[i+1][j+1]=2;
		}
		else{
			if(dp[i][j+1]<dp[i+1][j]){
				dp[i+1][j+1]=dp[i+1][j];
				from[i+1][j+1]=1;
			}
			else{
				dp[i+1][j+1]=dp[i][j+1];
				from[i+1][j+1]=0;
			}
		}
	}

	int idx=dp[m][n];
	string ans(idx,'@');
	for(int i=m,j=n;~from[i][j];){
		switch(from[i][j]){
			case 0: i--; break;
			case 1: j--; break;
			case 2: i--; j--; idx--; ans[idx]=s[i]; break;
		}
	}

	return ans;
}

int main(){
	for(string s;cin>>s,s!="#END";){
		int len=s.length();
		string ans;
		for(int i=1;i<len;i++){
			if(min(i,len-i)<=ans.length()) break;
			string tmp=LCS(s.substr(0,i),s.substr(i));
			if(ans.length()<tmp.length()) ans=tmp;
		}
		cout<<ans<<endl;
	}

	return 0;
}