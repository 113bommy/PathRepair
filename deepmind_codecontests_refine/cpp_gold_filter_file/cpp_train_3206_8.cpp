#include<iostream>
using namespace std;

int main() {
    long long A, B, K;
    cin >> A >> B >> K;
    printf("%lld %lld\n", max(0ll, A - K), max(0ll, B - max(0ll, K - A)));
}