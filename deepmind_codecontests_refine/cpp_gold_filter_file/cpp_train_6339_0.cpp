#include<iostream>
using namespace std;

int main(){
    int N,C,p[200];
    cin>>N>>C;
    int sum=0;
    for(int i=0;i<C;i++){
        cin>>p[i];
        sum+=p[i];
    }

    cout<<sum/(N+1)+(sum%(N+1)!=0)<<endl;

    return 0;
}
