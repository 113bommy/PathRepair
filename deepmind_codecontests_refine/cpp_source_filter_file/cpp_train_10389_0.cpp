#include<bits/stdc++.h>

using namespace std;

#define ll  long long
#define ld  double

#define sz(x)   (int)x.size()
#define all(x)  x.begin(),x.end()

#define pb  emplace_back
#define X   first
#define Y   second

const int   N   = 5e4;

typedef pair<int,int>   ii;
typedef bitset<N>       bs;

int main()  {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;  cin >> n;
    int m;  cin >> m;
    int T;  cin >> T;

    vector<ii>  E;

    for(int i = 0 ; i < m ; ++i)    {
        int x;  cin >> x;
        int y;  cin >> y;

        E.pb(x,y);
    }

    reverse(all(E));

    if (T == 1) {
        vector<bs>  f(n,0);
        bs  S;

        for(int i = 0 ; i < n ; ++i)    f[i][i] = S[i] = 1;
        for(int i = 0 ; i < m ; ++i)    {
            int x = E[i].X - 1;
            int y = E[i].Y - 1;

            f[x] = f[y] = (f[x] | f[y]);
        }

        for(int i = 0 ; i < n ; ++i)
            S &= f[i];

        int x = n;

        for(int i = 0 ; i < n ; ++i)
            if (S[i])   {
                x = i;
                break;
            }

        if (x < n)  {
            vector<int> t(n,0); t[x] = 1;

            string res = "";

            for(int i = 0 ; i < m ; ++i)    {
                int x = E[i].X - 1;
                int y = E[i].Y - 1;

                if (t[x])   res += '^', t[y] = 1;
                else        res += 'v', t[x] = t[y];
            }
            reverse(all(res));  cout << res << endl;
        }
        else    cout << "-1";
    }
    if (T == 2) {
        if (n < 3)  return  cout << "-1",0;

        vector<int> f(n);
        vector<int> c(n);

        iota(all(f),0);
        fill(all(c),1);

        string res = "";

        for(int i = 0 ; i < m ; ++i)    {
            int x = E[i].X - 1;
            int y = E[i].Y - 1;

            if (c[f[x]] > 1)
                c[f[x]]--,
                c[f[y]]++,
                f[x] = f[y],
                res += 'v';
            else
                c[f[y]]--,
                c[f[x]]++,
                f[y] = f[x],
                res += '^';
        }
        reverse(all(res)));  cout << res << endl;
    }
}