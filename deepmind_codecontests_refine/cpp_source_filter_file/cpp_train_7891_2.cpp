#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    long S; cin>>S;

    int ans=1000;
    while(S){
        ans=min(ans,abs(S%1000-753));
        S/=10;
    }
    cout<<ans<<endl;
}