#include <bits/stdc++.h>

using namespace std;

int co[256];
int n,k;
string arr[10004];

int get()
{
    int i;
    int ans=0;
    for(i=0;i<255;i++)
        if(!co[i])
            return i;
}

void del()
{
    int i;
    for(i=0;i<k&;i++)
    {
        co[i]--;
    }
}

int main()
{
    cin >> n >> k;
    int i;
    for(i=0;i<n;i++)
    {
        cin >> arr[i];
        co[arr[i][0]]++;
    }
    int ans=0;
    while(1)
    {
        sort(co,co+n);
        reverse(co,co+n);
        if(get()>=k)
        {
            ans++;
            del();
        }
        else
        {
            break;
        }
    }
    cout << ans << endl;
}
