#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;
long long main(void){
    long long N;
    cin >> N;
    vector<long long> L, R;
    L.resize(N+1); R.resize(N+1);
    L[0] = 0; R[0] = 0;
    for(long long i=1; i<N+1; ++i) cin >> L[i] >> R[i];
    sort(L.begin(), L.end(), greater<long long>());
    sort(R.begin(), R.end());
    long long ans = 0;
    for(long long i=0; i<N+1; ++i){
        ans += 2 * max(0LL, L[i]-R[i]);
    }
    cout << ans << endl;
}