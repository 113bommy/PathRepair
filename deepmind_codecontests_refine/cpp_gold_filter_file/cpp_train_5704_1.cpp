#include <bits/stdc++.h>
using namespace std;
// define #Asukaminato is cute
#define ll long long
#define rep(i, m) for (int i = 0; i < (int)(m); i++)
const int inf = 1000000000; // 10^9 Ten to the power of nine.


int main(){
	int H,W,M[102][102]={0};
	bool A[102][102]={0};
	char s;
	cin>>H>>W;
	for(size_t i=0;i<=H+1;i++)for(size_t j=0;j<=W+1;j++){
		if(i==0||i==H+1||j==0||j==W+1)M[i][j]=H*W;
		else{
			cin>>s;
			A[i][j]= (s!='#');
			if(i==1&&j==1){M[i][j]=!A[i][j];}
			else M[i][j]=min(M[i-1][j]+(A[i-1][j]&&!A[i][j]),M[i][j-1]+(A[i][j-1]&&!A[i][j]));
		}}
	
	cout<<M[H][W]<<endl;
	return 0;}