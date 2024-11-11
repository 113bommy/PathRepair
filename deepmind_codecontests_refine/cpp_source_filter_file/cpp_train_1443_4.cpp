#include <iostream>

using namespace std;

int main() {
    int n;

    cin >> n;

    int a[100010], count[100010] = {0};

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        count[a[i]]++;
    }

    if (n%2 == 1) {
        count[0]++;
    }

    for (int i = (n+1)%2; i < n; i += 2) {
        if (conut[i] != 2) {
            cout << 0 << endl;
            return 0;
        }
    }

    long long ans = 1;

    for (int i = 0; i < n/2; i++) {
        ans *= 2;
        ans %= 1000000007;
    }
    
    cout << ans << endl;
    return 0;
}
