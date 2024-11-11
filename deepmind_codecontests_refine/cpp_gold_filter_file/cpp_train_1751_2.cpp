#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define rep1(i,n) for(int i=1;i<=int(n);++i)
#define all(a) (a).begin(),(a).end()

ll n;

vector<ll> calc(vector<ll> &a) {
    vector<ll> sum(n);
    stack<int> stack;
    ll cnt = 0;
    rep1(i,n-1){
        ll pre = a[i-1], cur = a[i];
        if (pre >= cur) {
            while (pre >= cur*4) {
                cur *= 4;
                stack.push(i);
            }
        } else {
            while (pre < cur) {
                if (stack.empty()) {
                    cnt += i*2;
                } else {
                    int k = stack.top(); stack.pop();
                    cnt += (i-k)*2;
                }
                pre *= 4;
            }
        }
        sum[i] = cnt;
    }
    return sum;
}

int main(void){
    cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    vector<ll> l = calc(a);
    reverse(all(a));
    vector<ll> r = calc(a);
    reverse(all(r));

    ll res = r[0];
    rep1(i,n-1){
        res = min(res, l[i-1] + i + r[i]);
    }
    cout << res << endl;
    return 0;
}
