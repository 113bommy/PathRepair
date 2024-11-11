#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> P;

int dxy[4] = {-1, 1, 0, 0};
int W, H;
char a[60][60];
int temp[4][60][60];

void huga(int y, int x, int Z){//cout<<y<<" "<<x<<endl;
	int w = 0, b = 0, s = 0, ans=-3, t;
	queue <P> Q;
	
	Q.push(P(y,x));
	
	while(!Q.empty()){
		P p = Q.front();Q.pop();
		int yy = p.first, xx = p.second;//cout<<yy<<" "<<xx<<endl;
		for(int i = 0; i <= 3; i++){
			int nx = xx+dxy[i], ny = yy+dxy[3-i];//cout<<" "<<ny<<" "<<nx<<endl;
			if(a[ny][nx] == '.' && !temp[Z+2][ny][nx]) {
				temp[Z+2][ny][nx] = temp[Z][ny][nx] = 1;
				Q.push(P(ny,nx));
				//cout<<temp[2][ny][nx]<<" "<<temp[Z][ny][nx]<<" AA"<<endl;
			}
			//int fds; cin>>fds;
		}
	}
}

int main(){
	
	while(1){
		int cw=0, cb=0;
		cin>>W>>H;
		
		if(!W&&!H)break;
		
		for(int i = 0; i <= H+1; i++)
			for(int j = 0; j <= W+1; j++)
				temp[0][i][j] = temp[1][i][j] = temp[2][i][j] = temp[3][i][j] = 0;
				
		for(int i = 0; i < 60; i++){
			a[0][i] = a[H+1][i] = 0;
			a[i][0] = a[i][W+1] = 0;
		}
			
		for(int i = 1; i <= H; i++)
			for(int j = 1; j <= W; j++)
				cin>>a[i][j];
		
		for(int i = 1; i <= H; i++){
			for(int j = 1; j <= W; j++){
				//if(temp[2][i][j])continue;
				if(a[i][j] == 'B') huga(i,j,0);
				else if(a[i][j] == 'W') huga(i,j,1);
			}
		}
		
		for(int i = 1; i <= H; i++){
			for(int j = 1; j <= W; j++){
				if(a[i][j] == '.'){
					if(temp[0][i][j] && !temp[1][i][j])cb++;
					else if(!temp[0][i][j] && temp[1][i][j])cw++;
				}
			}
		}
		
		cout<<cb<<" "<<cw<<endl;
	}
	
	
	
	return 0;
}
