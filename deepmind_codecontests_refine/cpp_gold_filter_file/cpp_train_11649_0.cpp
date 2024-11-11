#include<bits/stdc++.h>
using namespace std;

const int dx[]={-1,0,1,0};
const int dy[]={0,-1,0,1};

int H,W;
int fld[10][10];
int lim;
void change(int y,int x,int c,int f){
    fld[y][x]=c;
    for(int d=0;d<4;d++){
        int ny=y+dy[d],nx=x+dx[d];
        if(ny<0||ny>=H||nx<0||nx>=W||fld[ny][nx]!=f)continue;
        change(ny,nx,c,f);
    }
}

bool dfs(int t=0){
    bool ok=true;
    for(int i=0;i<H;i++)for(int j=0;j<W;j++){
        if(fld[0][0]!=fld[i][j])ok=false;
    }
    if(ok)return true;
    if(t==lim)return false;

    int _fld[10][10];
    for(int i=0;i<H;i++)for(int j=0;j<W;j++){
        _fld[i][j]=fld[i][j];
    }

    bool ret=false;
    for(int k=0;k<3;k++)if(k!=fld[0][0]){
        change(0,0,k,fld[0][0]);
        ret|=dfs(t+1);
        for(int i=0;i<H;i++)for(int j=0;j<W;j++){
            fld[i][j]=_fld[i][j];
        }
    }

    return ret;
}
int main(){
    while(cin>>W>>H,W||H){
        for(int i=0;i<H;i++){
            for(int j=0;j<W;j++){
                char c;
                cin>>c;
                switch(c){
                case 'R':fld[i][j]=0;break;
                case 'G':fld[i][j]=1;break;
                case 'B':fld[i][j]=2;break;
                }
            }
        }

        for(lim=0;;lim++)if(dfs())break;
        cout<<lim<<endl;
    }

    return 0;
}