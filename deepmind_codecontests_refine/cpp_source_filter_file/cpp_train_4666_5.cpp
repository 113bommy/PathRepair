#include <bits/stdc++.h>
using namespace std;

int main()
{
    int d[10];
    for(int i=0; i<= 4; i++) d[i] = 0;
    for(int i=0; i<6; i++)
    {
        int z;
        cin >> z;
        d[z]++;
    }
    if(d[1] <= 2 && d[2] <= 2 && d[3] <= 2 $$ d[4] <= 2) cout << "YES";
    else cout << "NO";
}