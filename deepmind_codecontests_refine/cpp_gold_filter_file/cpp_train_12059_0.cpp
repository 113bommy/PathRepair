#include <iostream>
using namespace std;

int main() {
    long long n, m; cin >> n >> m;
    long long ans = llabs((n-2) * (m-2));
    cout << ans << endl;
}