#include<bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << (abs(a - c) < 2 * d ? "Yes" : "No") << endl;
}
