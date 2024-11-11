#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> P;
typedef vector<int> VI;
typedef vector<VI> VVI;

int dice[6][4]={{1,2,4,3},{0,3,5,2},{0,1,5,4},{0,4,5,1},{0,2,5,3},{1,3,4,2}};
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};

void solve(int x,int y,VVI& v,VVI& w,int top,int face){
    //cout<<x<<" "<<y<<" "<<top<<" "<<face<<endl;
    vector<P> vec;
    int var=-1;
    for(int i=0;i<4;i++) if(dice[top][i]==face)var=i;
    for(int i=0;i<4;i++){
        int nx=x+dx[i],ny=y+dy[i];
        if(v[nx][ny]<v[x][y] && dice[top][(i+var)%4]>=3){
            vec.push_back(P(dice[top][(i+var)%4],i*11+var));
        }
    }
    if(vec.size()==0){
        v[x][y]++;
        w[x][y]=top;
        return ;
    }
    sort(vec.rbegin(),vec.rend());
    int i=vec[0].second/11,va=vec[0].second%11;
    if(i==0)solve(x+dx[i],y+dy[i],v,w,dice[top][(2+va)%4],top);
    if(i==1)solve(x+dx[i],y+dy[i],v,w,dice[top][(3+va)%4],dice[top][(0+va)%4]);
    if(i==2)solve(x+dx[i],y+dy[i],v,w,dice[top][(0+va)%4],5-top);
    if(i==3)solve(x+dx[i],y+dy[i],v,w,dice[top][(1+va)%4],dice[top][(0+va)%4]);
    return ;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n;
  while(true){
      cin>>n;if(n==0)break;
      std::vector<int> res(6,0);
      VVI top(200,vector<int>(200,-1)),num(200,vector<int>(200,0));
      for(int i=0;i<n;i++){
          int t,f;cin>>t>>f;t--;f--;
          solve(100,100,num,top,t,f);
      }
     for(int i=0;i<200;i++)for(int j=0;j<200;j++) if(top[i][j]!=-1)res[top[i][j]]++;
      for(int i=0;i<6;i++){cout<<res[i];
      if(i==5)cout<<endl;
      else cout<<" ";}
  }
}