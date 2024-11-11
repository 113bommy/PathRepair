#include<iostream>
#include<climits>
#include<algorithm>
#include<cmath>
using namespace std;
int main()
{
    int n, k, x[100000], ans = INT_MAX;
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> x[i];
    }
    for(int i = 0; i <= n - k; i++){
        ans = min(ans, x[i+k-1] - x[i] + min(abs(x[i]), abs(x[i+k-1]));
    }
    cout << ans << endl;
    return 0;
}