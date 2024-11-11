#include <iostream>
#include <algorithm>

using namespace std;

typedef long long lint;
typedef unsigned long long ulint;
#define MOD 1000000007

int main(){
    int N;
    cin >> N;
    lint A[100000],B[100000],C[100000];
    for(int i=0;i<N;i++) cin >> A[i];
    for(int i=0;i<N;i++) cin >> B[i];
    for(int i=0;i<N;i++) cin >> C[i];
    
    sort(A,A+N);
    sort(B,B+N);
    sort(C,C+N);

    lint ans=0;
    for(int i=0;i<N;i++){
        ans+=distance(A,lower_bound(A,A+N,B[i]))*distance(upper_bound(C,C+N,B[i]),C+N);
    }

    cout << ans << endl;

    return 0;
}