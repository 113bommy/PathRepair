#include<bits/stdc++.h>
using namespace std;
int main(){
    int h,w;
    cin>>h>>w;
    char ch[52][52];
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++)cin>>ch[i][j];
    }
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            if(ch[i][j]=='#'&&ch[i][j-1]=='.'&&ch[i][j+1]=='.'&&ch[i+1][j]=='.'&&ch[i-1][j]=='.'){
                cout<<"No"<<endl;
                return 0;
            }
        }
    }
    cout<<"Yes"<<endl;
}