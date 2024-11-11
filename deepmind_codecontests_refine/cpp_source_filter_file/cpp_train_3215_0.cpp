# define _CRT_SECURE_NO_WARNINGS 1
# include <iostream>
# include <string>
# include <vector>
# include <algorithm>
# include <cstdlib>
# include <cstdio>
# include <cstring>
# include <cstdlib>
# include <iomanip>
# include <queue>
# include <sstream>
# include <climits>
# include <cmath>
# include <list>
# include <functional>
# include <string>
# include <set>
# include <map>
# include <stack>
using namespace std;
# define M_PI 3.141592
# define FOR(i,n) for(int i=0;i<(int)n;i++)
# define FORI(i,k,n) for(int i=k;i<(int)n;i++)
# define toRad 2.0*M_PI/360.0
# define inin(x) int x;cin>>x;
# define all(x) x.begin(),x.end()
# define debug(x) cout<<#x<<" :"<<x<<endl;
# define rep(i,n) for(int i=0;i<(int)n;i++)
# define EPS 1e-12
# define pri_max 60000
# define CHECK(i,a) FOR(i,a.size())cout<<#a<<"["<<i<<"] : "<<a[i]<<endl; 
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<int> vi;
typedef vector<vi> vvi;
 
 
int main()
{
    string formula;
    while (cin >> formula)
    {
        string a[3];
        int r = 0;
        for (int i = 0; i < formula.size(); i++)
        {
            if (formula[i] == '='||formula[i] == '+') {
                r++; continue;
            }
            a[r] += formula[i];
        }
        bool flag = true;
        for (char x = '0'; x <= '9'; x++)
        {
            if (x == '0' && ((a[0][0] == 'X'&&a[0].size>=2) ||( a[1][0] == 'X'&&a[1].size()>=2) || (a[2][0] == 'X'&&a[2].size()>=2)))continue;
            string b[3];
            for (int i = 0; i < 3; i++)
            {
                for (int l = 0; l < a[i].size(); l++)
                {
                    if (a[i][l] == 'X')
                    {
                        b[i] += x;
                    }
                    else
                    {
                        b[i] += a[i][l];
                    }
                }
            }
 
            for (int i = 0; i < 3; i++)
            {
                reverse(all(b[i]));
                int s = 100 - b[i].size();
                for (int l = 0; l < s; l++)
                {
                    b[i] += "0";
                }
            }
 
            for (int i = 0; i < 100; i++)
            {
                b[0][i] += b[1][i] - '0';
                if (b[0][i]>'9')
                {
                    b[0][i] = '0' + b[0][i] - '9' - 1;
                    b[0][i + 1]++;
                }
            }
            if (b[0] == b[2])
            {
                cout << x << endl;
                flag = false;
            }
        }
        if (flag)cout << "NA" << endl;
    }
}