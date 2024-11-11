#include<iostream>
using namespace std;
long long n,a[100000],b[100000],cnt;
int main(){
    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i]>>b[i];
    for(int i=n-1;i>=0;i--){
        a[i]+=cnt;
        if(a[i]%b[i])cnt+=b[i]-a[i]%b[i];
    }
    cout<<cnt<<endl;
}