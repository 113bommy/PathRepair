#include<bits/stdc++.h>
using namespace std;
const int SIZE=55;
const int dr[]={-1,-1,-1,0,0,1,1,1};
const int dc[]={-1,0,1,-1,1,-1,0,1};
int H,W;
char M[SIZE][SIZE];
int count(int x,int y){
	int sum=0,r,c;
	for(int i=0;i<8;i++){
		r=x+dr[i];
		c=y+dc[i];
		if(r>=0&&r<H&&c>=0&&c<W&&M[r][c]=='#')sum++;
	}
	return sum;
}
int main(){
	cin>>H>>W;
	for(int i=0;i<H;i++)cin>>M[i];
	for(int i=0;i<H;i++)
		for(int j=0;j<W;j++)
			if(M[i][j]=='.')M[i][j]='0'+count(i,j);
	for(int i=0;i<H;i++)cout<<M[i]<<endl;
	return 0;
}
