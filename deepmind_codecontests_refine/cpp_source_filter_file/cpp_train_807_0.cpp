#include<bits/stdc++.h>
using namespace std;
typedef long long int64;
typedef pair<int64, int64> pii;
//int64 dp[2002][2002];
vector<pii> A(2002);
int n;
map<vector<int>, int64> dp;
int64 solve(int l, int r, int pos){
   if(l > r) return 0;
   if(pos >= n) return 0;
   //int64 &ret = dp[{l, r, pos}];
   //if(ret > 0) return ret;
   in64 ret = A[pos].first * abs(A[pos].second - l) + solve(l + 1, r, pos + 1);
   ret = max(ret, A[pos].first * abs(A[pos].second - r) + solve(l, r - 1, pos + 1));
   return ret;
}
int main(){
	cin >> n;
    for(int i = 0; i < n; i++){
    	cin >> A[i].first;
        A[i].second = i;
    }
    sort(A.rbegin(), A.rend());
    //memset(dp, -1, sizeof(dp));
    int64 ans = solve(0, n - 1, 0);
    cout << ans << endl;
    return 0;
}
