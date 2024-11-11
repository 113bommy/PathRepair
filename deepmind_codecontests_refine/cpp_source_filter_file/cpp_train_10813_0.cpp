#include<bits/stdc++.h>
using namespace std;
int main()
{
    int f[]={4,1,4,1,2,1,2,1},p[8],r,P;
    while(cin>>p[0]){
        for(int i=1;i<8;i++)cin>>p[i];
        for(int i=0;i<8;i++){
            int n=0;
            for(int j=0;j<8;j++)if(f[(i+j)%8]<p[j])n+=p[j]-f[(i+j)%8];
            if(r>n||i==0){
                r=n;
                P=i;
            }
            else if(r==n){
                for(int j=0;j<8&&f[(i+j)%8]<=fl[(P+j)%8];j++){
                    if(f[(i+j)%8]<f[(P+j)%8]){
                        P=i;
                        break;
                        }
                    }
                }
        }
        for(int i=0;i<7;i++)cout<<f[(P+i)%8]<<" ";
            cout<<f[(P+7)%8]<<endl;
    }
}