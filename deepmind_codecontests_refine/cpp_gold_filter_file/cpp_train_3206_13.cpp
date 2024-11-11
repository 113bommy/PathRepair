#include <iostream>
using namespace std;

int main() {
    long long A, B, K;
    cin >> A >> B >> K;
    if (A <= K) cout << 0 << " " << max(A+B-K, 0LL) << endl;
    else cout << A-K << " " << B << endl;
}
