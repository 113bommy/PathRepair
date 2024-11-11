#include <iostream>
#include <queue>

using namespace std;
typedef pair<int, int> P;

void seach(int x,int y,int X,int Y);

int speace[5000][5000],n;

int main(){
	int X,Y,N,x1,y1,x2,y2;
	while(1){
	cin >> X >> Y;
		if(X==0&&Y==0){
			break;
		}
	cin >> N;
	n=0;
	for(int i=0;i<X;i++){
		for(int j=0;j<Y;j++){
			speace[i][j]=-1;
		}
	}
	for(int i=0;i<N;i++){
		cin >> x1>>y1>>x2>>y2;
		for(int j=x1;j<x2;j++){
			for(int k=y1;k<y2;k++){
				speace[j][k]=n;
			}
		}
	}
	n++;
	for(int i=0;i<X;i++){
		for(int j=0;j<Y;j++){
			if(speace[i][j]==-1){
				seach(i,j,X,Y);n++;
				
			}
		}
	}
		/*cout << "\n";
		for(int i=0;i<X;i++){
			for(int j=0;j<Y;j++){
				cout << speace[i][j] << " ";
			}
			cout << "\n";
		}*/
	cout << n-1 <<"\n";
	}
	return 0;
}

void seach(int x,int y,int X,int Y){
	int dx[4]={-1,0,0,1},dy[4]={0,1,-1,0};
	queue<P> que;
	que.push(P(x,y));
	while(que.size()){
		P p=que.front();
		que.pop();
		for(int i=0;i<4;i++){
			if(0<=p.first+dx[i]&&p.first+dx[i]<X&&0<=p.second+dy[i]&&p.second+dy[i]<Y){
				if(speace[p.first+dx[i]][p.second+dy[i]]==-1){
					speace[p.first+dx[i]][p.second+dy[i]]=n;
					que.push(P(p.first+dx[i],p.second+dy[i]));
				}
			}
		}
	}
}
			
	