#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, s, ans=0, min=101;
    cin >> n;
    vector<int> dp(n);
    for (int i=0; i<n; i++)
    {
        cin >> s;
        ans+=s;
        if (s%10!=0) min=s;
    }
    if (ans%10!=0)cout << ans << endl;
    else if (min==101) cout << 0 << endl;
    else cout << ans-min << endl;
    return 0;
} 