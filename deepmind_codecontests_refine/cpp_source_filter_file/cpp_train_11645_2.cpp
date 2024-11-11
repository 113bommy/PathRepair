#include<bits/stdc++.h>
using namespace std;

int main(){

    long long n, a, b; cin >> n >> a >> b;
    cout << max(0, (2 - n) * (a - b) + 1) << endl;
    return 0;
}