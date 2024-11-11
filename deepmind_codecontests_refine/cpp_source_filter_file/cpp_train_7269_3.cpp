#include<iostream>
using namespace std;
int main(){
    int N,Y;
    int i,j;
    cin>>N>>Y;
    for(i=1;i<=N;i++ ){
    for(j=0;j<=N;j++ ){
    if(Y==10000*i+5000*j+1000*(N-i-j)&&i+j<=N)
    {cout<<i<<" "<<j<<" "<<N-i-j<<endl;
     goto A;
    }
    }}
    cout<<-1<<" "<<-1<<" "<<-1<<endl;
    A:
    }