#include<iostream>
#include<cmath>
using namespace std;

typedef long long ll;

int N;
int S[100001];

int main() {
    cin>>N;
    for(int i=0;i<N;i++) cin>>S[i];

    ll res = 0;
    for(int i=1;i<N;i++) {
        int l=i, r=N-1-i;
        if(l>=r) break;
        ll val=0;
        if((N-1)%i) {
            while(i<r) {
                val+=S[l]+S[r];
                res=max(res,val);
                l+=i,r-=i;
            }
        } else {
            while(l<r) {
                val+=S[l]+S[r];
                res=max(res,val);
                l+=i,r-=i;
            }
        }
    }
    cout<<res;
}