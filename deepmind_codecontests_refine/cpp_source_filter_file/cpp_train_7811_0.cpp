#include<iostream>
#include<deque>

using namespace std;

typedef long long ll;

#define rep(i,n) for(ll i=0;i<(n);i++)

ll N,L,a[1000000],b[1000000];
deque<ll> deq;

int main() {
    cin >> N >> L;

    rep(i,N)cin >> a[i];

    rep(i,N) {

        while(!deq.empty() && a[deq[deq.size() - 1]] >= a[i]) deq.pop_back();
        deq.push_back(i);

        if(i - L + 1 >= 0) {
            b[i - L + 1] = a[deq[0]];

            if(deq[0] == i - L + 1) {
                deq.pop_front();
            }
        }
    }

    rep(i,N - L + 1) {
        cout << b[i];
        if(i < N - L)cout << " ";
    }
    cout << endl;
    return 0;

