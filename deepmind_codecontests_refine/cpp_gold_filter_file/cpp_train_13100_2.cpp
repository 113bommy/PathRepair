#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int N;
    cin>>N;
    vector<ll>a;
    for(int i=0;i<N;i++){
        ll t;
        cin>>t;
        a.push_back(t);
    }
    sort(a.begin(), a.end());
    ll max1=0,max2=0;
    for(int i=1;i<N;i++){
        if(a[i-1]==a[i]){
            max2=max1;
            max1=a[i];
            i++;
        }
    }
    cout<<max1*max2<<endl;
    return 0;
}
