#include <bits/stdc++.h>
#define all(vec) vec.begin(),vec.end()
using namespace std;
using ll=long long;
using P=pair<ll,ll>;
const ll INF=1LL<<30;
const ll LINF=1LL<<61;
const double eps=1e-9;
const ll MOD=1e9+7;
int main(){
    int n;cin>>n;
    vector<int> a(n);
    int sum=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    sort(all(a[i]));
    if(sum%2==0){
        cout<<sum/2<<endl;
        return 0;
    }
    for(int i=0;i<n;i++){
        if(a[i]%2){
            cout<<(sum-a[i])/2<<endl;
            return 0;
        }
    }
}

