#include<iostream>
using namespace std;
int mp[2][31][31]={};
int sai[7][4]= {{0,0,0,0},{3,5,4,2},{1,4,6,3},{1,2,6,5},{5,6,2,1},{3,6,4,1},{2,4,5,3}};

void die(int t,int f,int x,int y){
  int i,j,x2,y2,mx=3,f2,t2,dx[4]={0,1,0,-1},dy[4]={-1,0,1,0};
  mp[1][y][x]++;
  for(i=0;i<4;i++){
    if(sai[t][i]==f){
      for(j=i;j<i+4;j++){
	int m=j%4,x1=x+dx[j-i],y1=y+dy[j-i];
	if(mp[1][y][x]-1>mp[1][y1][x1]&&sai[t][m]>mx){
	  mx=sai[t][m],x2=x1,y2=y1,t2=7-mx;
	  if(j-i==2)f2=7-t;
	  else if(j-i==0)f2=t;
	  else f2=f;
	}
      }
      break;
    }
  }
  if(mx!=3)mp[1][y][x]--,die(t2,f2,x2,y2);
  else mp[0][y][x]=t;
}

int main(){
  while(1){
    int n;cin>>n;if(n==0)break;
    int i,j,t,f,c[7]={};
    for(i=0;i<n;i++){
      cin>>t>>f;
      die(t,f,15,15);
    }
    for(i=0;i<31;i++)
      for(j=0;j<31;j++){
	c[mp[0][i][j]]++;
	mp[0][i][j]=mp[1][i][j]=0;
      }
    for(i=1;i<6;i++)cout<<c[i]<<" ";cout<<c[6]<<endl;
  }
  return 0;
}