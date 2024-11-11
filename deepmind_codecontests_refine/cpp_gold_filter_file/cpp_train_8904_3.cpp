#include <iostream>
#include <cstdio>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <iterator>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define x0 abc
#define y0 ABC
#define x1 abcd
#define y1 ABCD
#define xn abcde
#define yn ABCDE

#define l_b lower_bound
#define u_b upper_bound

#define in insert
#define er erase

#define fi first
#define se second
#define m_p make_pair

#define p_b push_back
#define po_b pop_back

#define uns unsigned

#define ld long double
#define ll long long

#define cont continue
#define re return

#define MAXLL 9000000000000000000LL
#define MAXINT 2000000000

#define MINLL -9000000000000000000LL
#define MININT -2000000000

#define pi acos(-1.)

#define endl '\n'

#define OUT cout << "-------" << endl;

using namespace std;

using namespace __gnu_pbds;

typedef tree <int, null_type, less <int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int a[1201][1201], n, m, i, j, t, kol;

    int Abs(int a)
    {
        re (a < 0 ? -a : a);
    }

    void solve()
    {
        cin >> n >> m;

        for (i = 1; i <= n; i++)
            for (j = 1; j <= m; j++) cin >> a[i][j];

        kol = 0;

        for (i = 1; i <= m; i++)
            if (Abs(a[n / 2][i] - a[n / 2 + 1][i]) > 120) kol++;

        if (kol > 0)
        cout << "YES";
        else cout << "NO";

        cout << endl;
    }

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;

    while (t--) solve();

    re 0;
}
