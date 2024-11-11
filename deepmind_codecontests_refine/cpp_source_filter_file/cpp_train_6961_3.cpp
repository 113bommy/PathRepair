#include<bits/stdc++.h>
#define rep(i,n)for(int i=0;i<n;i++)
using namespace std;

char s[18][18];
string buf;
int main(){
	do{
		memset(s,0,sizeof(s));
		for(int i=1;i<=8;i++)scanf("%s",s[i]+1);
		for(int i=1;i<=8;i++){
			for(int j=1;j<=8;j++){
				if(s[i][j]!='1')continue;
				if(s[i][j+1]=='1'&&s[i+1][j+1]=='1'&&s[i+1][j]=='1'){puts("A");goto p;}
				if(s[i+1][j]=='1'&&s[i+2][j]=='1'&&s[i+3][j]=='1'){puts("B");goto p;}
				if(s[i][j+1]=='1'&&s[i][j+2]=='1'&&s[i][j+3]=='1'){puts("C");goto p;}
				if(s[i+1][j-1]=='1'&&s[i+1][j]=='1'&&s[i+2][j-1]=='1'){puts("D");goto p;}
				if(s[i][j+1]=='1'&&s[i+1][j+1]=='1'&&s[i+1][j+2]=='1'){puts("E");goto p;}
				if(s[i+1][j]=='1'&&s[i+1][j+1]=='1'&&s[i+2][j+1]=='1'){puts("F");goto p;}
				if(s[i][j+1]=='1'&&s[i+1][j-1]=='1'&&s[i+1][j]=='1'){puts("G");goto p;}
			}
		}
		p:
	}while(getline(cin,buf));
	return 0;
}