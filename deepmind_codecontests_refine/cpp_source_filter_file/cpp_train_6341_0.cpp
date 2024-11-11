#include <bits/stdc++.h>
using namespace std;
int xv[]={1,1,1,1,1,2,2,2,3},yv[]={2,1,0,-1,-2,1,0,-1,0};

void solve(int w,int h){
    char in;
    bool l;
    int r,c;
    stack<pair<bool,pair<int,int>>> q;
    pair<int,int> n;
    vector<vector<int>> mp=vector<vector<int>>(h+4,vector<int>(w+6,-1));
    vector<vector<vector<int>>> ma(h+4,vector<vector<int>>(w+6,vector<int>(2,INT_MAX/2)));
    set<pair<int,int>> sset,tset;
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            cin>>in;
            if(in=='X')mp[i+1][j+2]=-1;
            else if(in=='S'){
                mp[i+1][j+2]=0;
                sset.insert(make_pair(i+1,j+2));
            }
            else if(in=='T'){
                mp[i+1][j+2]=0;
                tset.insert(make_pair(i+1,j+2));
            }
            else{
                mp[i+1][j+2]=in-'0';
            }
        }
    }
    for(pair<int,int> x:sset){
        q.push(make_pair(true,make_pair(x.first,x.second)));
        q.push(make_pair(false,make_pair(x.first,x.second)));
        ma[x.first][x.second][0]=0;
        ma[x.first][x.second][1]=0;
    }
    while(!q.empty()){
        l=q.pop().first;n=q.front().second;q.pop();
        for(int i=0;i<9;i++){
            r=n.first+yv[i];
            c=n.second+(l?xv[i]:-1*xv[i]);
            if(mp[r][c]!=-1&&ma[n.first][n.second][!l]+mp[r][c]<ma[r][c][l]){
                ma[r][c][l]=ma[n.first][n.second][!l]+mp[r][c];
                q.push(make_pair(!l,make_pair(r,c)));
            }
        }
    }
    int mini=INT_MAX/2;
    for(pair<int,int> x:tset){
        mini=min(mini,ma[x.first][x.second][0]);
        mini=min(mini,ma[x.first][x.second][1]);
    }
    cout<<(mini!=INT_MAX/2?mini:-1)<<endl;
}

int main(){
    int w,h;
    while(cin>>w>>h,w){
        solve(w,h);
    }
}

