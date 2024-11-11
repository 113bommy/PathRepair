#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int num[]={0,1,2,3,4,5,6,7,8,9,5,4,3,2,1,0};
    for(int i=0,x,y;i<n;i++){
        cin>>x>>y;
        if(x<6&&y<6&&y-x>0){
            cout<<num[x];
            for(int j=x+1;j<=y;j++)cout<<" "<<num[j];
            cout<<endl;
        }
        else if(x<6&&y<6){
            cout<<num[15-x];
            for(int j=16-x;j<16-y;j++)cout<<" "<<num[j];
            cout<<endl;
        }
        else{
            cout<<num[x];
            for(int j=x+1;num[j-1]!=y;j++){
                if(j==16)j=1;
                cout<<" "<<num[j];
            }
            cout<<endl;
        }
    }
}