#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main(){
    int n,a,b,c,d;
    string s;
    bool ans=true;
    cin>>n>>a>>b>>c>>d>>s;
    for(int i=a-1;i<max(c,d)-1;i++){
        if(s[i]=='#'&&s[i+1]=='#'){
            cout<<"No"<<endl;
            return 0;
        }
    }
    if(c>d){
        ans = false;
        for(int i=b-2;i<min(c,d)-1;i++){
            if(s[i]=='.'&&s[i+1]=='.'&&s[i+2]=='.') ans = true;
        }
    }
    if(ans) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}