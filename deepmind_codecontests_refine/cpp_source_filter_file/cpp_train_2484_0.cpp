#include <iostream>
#include <map>

using namespace std;

int main() {
    int r = 0, n;
    cin >> n;
    map<int, int> m;
    for (int i = 0; i < n; ++i) {
        int a;
        scanf("%d", &a);
        r ^= a;
        int u = __builtin_ffs(a);
        if(!m[u-1]) m[u-1]=a;
    }
    int x = 1 << 30, ans = 0;
    for (int p = 30; p >= 0; --p) {
        if(r & x){
            if(!m[p]) {
                puts("-1");
                return 0;
            }else {
                r ^= m[p][0];
                r ^= (m[p][0]-1);
                ans++;
            }
        }
        x /= 2;
    }
    cout << ans << "\n";
    return 0;
}
