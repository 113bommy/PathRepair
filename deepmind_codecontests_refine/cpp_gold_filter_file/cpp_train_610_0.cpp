#include<bits/stdc++.h>
using namespace std;

int main(){
    int n=0,a=0,count=0,b=0,t=0;

    cin>>n;

        int x[3][100]={};    

    for(int i=0;i<3;i++){
        cin>>a;
        t=a;


        for(int j=0;j<t;j++){
            cin>>b;
            x[i][b-1]=1;

        }

    }


    for(int j=0;j<n;j++){
        
        if(x[0][j]==0 && x[2][j]==1){
            count++;
        }
        if(x[1][j]==1 && x[2][j]==1){
            count++;

        }
        if(x[0][j]==0 && x[1][j]==1 && x[2][j]==1){
            count--;
        }
    }
    cout<<count<<endl;



}
