#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    long long s;
    cin >> s;
    long long ans = INT_MAX;
    
    while(s!=0) {
        ans = min(ans, abs(753 - s%1000));
        s /= 10;
    }

    cout << ans << endl;
}
