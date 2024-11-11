#include<bits/stdc++.h>
using namespace std;
int const nax = 2048;
const int INF = 1e7;
int n;
int a[nax * 3];
int f[nax][nax];
int local_max[nax];
tuple <int, int, int> to_update[nax * 16]; /// never go more than this
/// it's O(n) but cannot tell exactly how large, should be no more than this
int top_update = 0;

void add_update (int x, int y, int z) {
    to_update[++ top_update] = make_tuple(x, y, z);
}


void shift_array (int *b) {
    static int tmp[3];
    for (int i = 0 ; i < 3; ++ i)
        tmp[i] = b[i];
    b[0] = tmp[1], b[1] = tmp[2], b[2] = tmp[0];
}

int main() {

    scanf("%d", &n);
    for (int i = 1; i <= 3 * n; ++ i)
        scanf("%d", a + i);
    for (int i = 0 ; i <= n + 10 ; ++ i)
    for (int j = 0 ; j <= n + 10; ++ j)
        f[i][j] = -INF;
    for (int i = 0 ; i <= n + 10 ; ++ i)
        local_max[i] = -INF;
    f[a[1]][a[2]] = f[a[2]][a[1]] = 0;
    local_max[a[1]] = local_max[a[2]] = 0;

    int to_add = 0;
    int ans = 0;


    for (int cur = 3 ; cur < 3 * n ; cur += 3) {
        if (a[cur + 1] == a[cur] && a[cur] == a[cur + 2]) {
            to_add += 1;
            continue;
        }

        static int b[3];
        b[0] = a[cur], b[1] = a[cur + 1], b[2] = a[cur + 2];

        for (int i = 0 ; i < 3 ; ++ i)
        for (int j = i + 1 ; j < 3 ; ++ j) {
            int k = 3 - i - j;
            add_update(b[i], b[j], ans);
            add_update(b[i], b[j], f[b[k]][b[k]] + 1);
        }

        for (int shift = 0; shift < 3 ; ++ shift) {
            shift_array(b);
            int x = b[0], y = b[1], z = b[2];
            for (int t = 1 ; t <= n ; ++ t) {
                if (y == z) {

                    add_update(x, t, f[t][y] + 1);
                }
                /// add new state
                add_update(y, z, f[x][x] + 1);
                add_update(x, t, local_max[t]);
            }
        }

        for (int i = 1 ; i <= top_update ; ++ i) {
            const auto &[x, y, z] = to_update[i];
            ans = max(ans, z);
            local_max[x] = max(local_max[x], z);
            local_max[y] = max(local_max[y], z);
            f[x][y] = max(f[x][y], z);
            f[y][x] = max(f[y][x], z);

        }
        top_update = 0;
    }


    ans = max(ans, f[a[3 * n]][a[3 * n]] + 1);
    printf("%d\n", ans + to_add);
}

