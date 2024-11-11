#include <iostream>
#include <string>
#include <cstdio>
#include <cctype>
#include <cstring>

using namespace std;

#define loop(i,a,b) for(int i=(a); i<int(b); i++)
#define rep(i,b) loop(i,0,b)

int main(){
    int n;
    while(cin>>n && n){
        static char g[2000][2000];
        memset(g,0,sizeof(g));
        rep(i,n){
            cin >> g[i];
            for(int j=0; g[i][j]=='.'; j++){
                if(g[i][j+1]=='.'){
                    g[i][j] = ' ';
                }else{
                    g[i][j] = '+';
                    break;
                }
            }
        }
        for(int i=1; i<n; i++){
            int j=0;
            for(g[i][j]!='+'; j++);
            int ii=i+1;
            for(;g[ii][j]==' '; ii++);
            if(g[ii][j]!='+') continue;
            for(int y=i+1;y<ii; y++){
                g[y][j]='|';
            }
        }

        rep(i,n){
            cout << g[i]<<endl;
        }
    }
}