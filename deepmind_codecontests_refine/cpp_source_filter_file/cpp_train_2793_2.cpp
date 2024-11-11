#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int mnx = 1e6 + 9;
const int mod = 1e9 + 7;

ll n;
ll a[mnx];
ll mn, mx;

int main() {

cin >> n;

for(int i = 1; i <= n; i++){
    cin >> a[i];
}

mn = 2; mx = 2;

for(int i = n; i >= 1; i--){
    if(mn % a[i] != 0) mn = a[i] * (mn / a[i] + 1);
    mx = a[i] * (mx / a[i] + 1) - 1;
}

if(mn > mx) return 0, cout << -1 << '\n';
else cout << mn << ' ' << mx << '\n';

return 0;

}
