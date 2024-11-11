#include<cstdio>
#include<algorithm>

using namespace std;

int masu[14][14];
int cont;

void saiki(int x,int y){
	masu[x][y]=0;
	if(masu[x+1][y]==1){
		saiki(x+1,y);
	}
	if(masu[x-1][y]==1){
		saiki(x-1,y);
	}
	if(masu[x][y+1]==1){
		saiki(x,y+1);
	}
	if(masu[x][y-1]==1){
		saiki(x,y-1);
	}
}

int main()
{
	while(1){
		for(int i=0;i<14;i++){
			for(int j=0;j<14;j++)
			masu[i][j]=0;
		}
		cont=0;
		
		char str[100];
		for(int i=1;i<=12;i++){
			if(scanf("%s",str)==EOF){
				goto A;
			}
			for(int j=1;j<=12;j++){
				if(str[j-1]=='1'){
					masu[i][j]=1;
				}
			}
		}
		
		for(int i=1;i<=12;i++){
			for(int j=1;j<=12;j++){
				if(masu[i][j]==1){
					saiki(i,j);
					cont++;
				}
			}
		}
		printf("%d\n",cont);
	}
	A:;
	
}