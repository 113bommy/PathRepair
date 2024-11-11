#include <iostream>
using namespace std;
int main(){
    long long a,b,c,delta=0;
    cin>>a>>b>>c;
    if(b>=a){
        cout<<1<<endl;
        goto endapp;
    }
    if(c>=b){
        cout<<-1<<endl;
        goto endapp;
    }
    if ((a-b)%(b-c)>=1)
        delta=1;
    cout<<((a-b)/(b-c)+delta)*2+1<<endl;
endapp:
    return 0;
}