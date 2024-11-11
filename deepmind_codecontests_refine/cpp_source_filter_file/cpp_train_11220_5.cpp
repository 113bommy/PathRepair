#include<iostream>
using namespace std;
int main()
{
    long n;
    cin>>n;
    long double a;
    long long ans=1;
    long double check=1;
    for(int i=0;i<n;i++){
        cin>>a;
        ans*=a;
        check*=a
    }
    if(ans>1000000000000000000)
        cout<<-1<<endl;
    else
        cout<<ans<<endl;
}