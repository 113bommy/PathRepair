#include "iostream"
#include "algorithm"
#include "string"
#include "vector"
#include "cmath"
#include "bitset"
#include "queue"
#include "functional"
#include "map"
#include "unordered_map"
#include "set"
#include "stack"
#include "tuple"

#define mod 1000000007
#define sp ' '
#define intmax 2147483647
#define llmax 92233720368547758070
#define nyan "(=^･ω･^=)"
#define mkp make_pair
#define mkt make_tuple
#define P pair<ll, ll>
#define iP pair<int,int>
typedef long long ll;
using namespace std;

ll H,W,a[200][200],dp[400][200][200]={};

int main(){
	cin>>H>>W;
	if(H==1||W==1){
		int ans=0;
		for(int i=0;i!=H;++i)
			for(int j=0;j!=W;++j){
				cin>>a[i][j];
				ans+=a[i][j];
			}
		cout<<ans<<endl;
		return 0;
	}
	for(int i=0;i!=H;++i)
		for(int j=0;j!=W;++j)
			cin>>a[i][j];
	for(int i=1;i!=H+W-2;++i){
		for(int j=max(0,i-H+1);j!=min(i,W-1);++j){
			for(int k=j+1;k!=min(i+1,W);++k){
				if(j)
					dp[i][j][k]=max({dp[i-1][j][k],dp[i-1][j-1][k],dp[i-1][j][k-1],dp[i-1][j-1][k-1]})+a[j][i-j]+a[k][i-k];
				else
					dp[i][j][k]=max(dp[i-1][j][k],dp[i-1][j][k-1])+a[j][i-j]+a[k][i-k];
			}
		}
	}
	cout<<a[0][0]+a[H-1][W-1]+dp[H+W-3][W-2][W-1]<<endl;
	return 0;
}
