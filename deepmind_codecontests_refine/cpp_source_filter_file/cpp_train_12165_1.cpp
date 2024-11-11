#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll arr[100005];


int main()
{
    ll n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        arr[a]+=b;
    }
    for(ill i=1;i<=100000;i++){
        k-=arr[i];
        if(k<=0){
            cout<<i;
            return 0;
        }
    }

}
