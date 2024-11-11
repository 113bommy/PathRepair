#include<iostream>
#include<map>
#include<string.h>
using namespace std;

int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};

int main()
{
	map<char,pair<int,int> > M;
	M['A']=make_pair(0,0);
	M['B']=make_pair(1,0);
	M['C']=make_pair(2,0);
	M['D']=make_pair(0,1);
	M['E']=make_pair(1,1);
	M['F']=make_pair(2,1);
	M['G']=make_pair(0,2);
	M['H']=make_pair(1,2);
	M['I']=make_pair(2,2);

	int n;
	while(cin>>n &&n!=0){
		char s,t,b;
		cin>>s>>t>>b;
		pair<int,int> now=M[s];
		pair<int,int> goal=M[t];
		pair<int,int> nota=M[b];

		double ans[17][3][3];

		for(int i=0;i<16;i++)
			for(int x=0;x<3;x++)
				for(int y=0;y<3;y++)
					ans[i][y][x]=0.0;

//		cout<<now.first<<" "<<now.second<<endl;
		ans[0][now.second][now.first]=1.0;

		for(int i=0;i<n;i++){
			for(int x=0;x<3;x++){
				for(int y=0;y<3;y++){
					for(int r=0;r<4;r++){
						int nx=x+dx[r],ny=y+dy[r];
						if(nx<0 || nx>=3 || ny<0 || ny>=3 || make_pair(nx,ny)==nota){
							ans[i+1][y][x]+=ans[i][y][x]/4.0;
						}
						else{
							ans[i+1][ny][nx]+=ans[i][y][x]/4.0;
						}
					}
				}
			}
		}
		cout<<ans[n][goal.second][goal.first]<<endl;
	}
	return 0;
}