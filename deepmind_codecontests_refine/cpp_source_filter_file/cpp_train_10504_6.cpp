#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int l, a, b, c, d; cin >> l >> a >> b >> c >> d;
    cout << (l - max(a / c + !!(a % c), b / d + !!(b % d)) << endl;
    return 0;
}