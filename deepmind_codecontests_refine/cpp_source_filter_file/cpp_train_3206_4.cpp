#include<iostream>
using namespace std;

int main() {
    int64_t A, B, K;
    cin >> A >> B >> K;
    printf("%lld %lld\n", max(0ll, A - K), max(0ll, B - max(0ll, K - A)));
}