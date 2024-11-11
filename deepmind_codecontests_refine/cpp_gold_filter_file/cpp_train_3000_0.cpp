#include <iostream>
using namespace std;
const string MIN = "(^ ω ^)";

int N, M;
int A[10];
int B[10] = {0,2,5,5,4,5,6,3,7,6};
string dp[10101]; // dp[i] := maximum num of using i matches

void chmax(string &a, string b) {
    if(a == MIN) a = b;

    if(a.size() < b.size()) a = b;
    else if(a.size() == b.size()) {
        if(a < b) a = b;
    }
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cin >> N >> M;
    for(int i=0;i<M;++i) cin >> A[i];

    for(int i=0;i<10101;++i) dp[i] = MIN;
    dp[0] = "";

    for(int i = 0;i < N;i++){
        if(dp[i] == MIN) continue;
        for(int a : A) chmax( dp[i + B[a]], dp[i] + (char)(a + '0') );
    }
    cout << dp[N] << '\n';
    return 0;
}