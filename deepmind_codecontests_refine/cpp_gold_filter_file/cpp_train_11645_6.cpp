#include<bits/stdc++.h>
using namespace std;

int main(){

    long long n, a, b; cin >> n >> a >> b;
    cout << max(0LL, (2 - n) * (a - b) + 1LL) << endl;
    return 0;
}