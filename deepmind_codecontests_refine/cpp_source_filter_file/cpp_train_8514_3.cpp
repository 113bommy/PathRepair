#pragma GCC optimize("Ofast")

#pragma GCC optimize("O3")

#include <bits/stdc++.h>

#define ll long long

using namespace std;

ll i, p, ans;

string s, t;

int main()
{
    cin >> s >> t;

    map < char, vector < ll > > a;

    for (; i<s.size(); i++) a[s[i]].push_back(i+1);

    for (i:t)
    {
        if (!a[i].size()) return cout << -1, 0;

        auto k=lower_bound(a[i].begin(), a[i].end(), p);

        if (k!=a[i].end())
        {
            ans+=*k-p;

            p=*k;
        }
        else
        {
            ans+=s.size()-p+*a[i].begin();

            p=*a[i].begin();
        }
    }

    cout << ans;
}
