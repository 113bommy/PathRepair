#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b;
    cin>>a>>b;
    char c[a][b];
    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++){
            cin>>c[i][j];
        }
    }
    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++){
            if(c[i][j]=='#'&&!(c[min(a-1,i+1)][j]=='#'||c[max(0,i-1)][j]=='#'||c[i][min(b-1,j+1)]=='#'||c[i][max(0,j-1)]=='#'){
                cout<<"No"<<endl;
                return 0;
            }
        }
    }
    cout<<"Yes"<<endl;
}
    