#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    while(cin>>n,n){
        int ans[2][12]={};
        for(int i=0;i<n;i++){
                cin>>ans[0][i];
                ans[1][i]=ans[0][i];
        }
        for(int i=0;;i++){
            int num[100]={};
            for(int j=0;j<n;j++)num[ans[0][j]]++;
            bool rever=1;
            for(int j=0;j<n;j++){
                ans[0][j]=num[kawa[j]];
                if(ans[0][j]!=ans[1][j])rever=0;
            }
            if(rever){
                cout<<i<<endl;
                for(int j=0;j<n-1;j++)cout<<ans[0][j]<<" ";
                cout<<ans[0][n-1]<<endl;
                break;
            }
            for(int j=0;j<n;j++)ans[1][j]=ans[0][j];
        }
    }
}