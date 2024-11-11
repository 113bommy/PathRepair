#include <iostream>
#include <fstream>
#include <map>
#include <vector>
using namespace std;
const int nmax=100005;
map<int,int> ap,norm;
vector<int> v[nmax];
int viz[nmax],a[nmax],b[nmax];
int n,i,j,nr,edges,cc;
void dfs(int x)
{
    viz[x]=1;
    for(int i=0;i<v[x].size();i++)
        if(!viz[v[x][i]])
           dfs(v[x][i]);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin>>n;
    for(i=1;i<=n;i++)
        cin>>a[i],a[0]^=a[i];
    for(j=1;j<=n;j++)
        cin>>b[j],b[0]^=b[j];
    for(i=0;i<=n;i++)
        ap[a[i]]++;
    for(i=0;i<=n;i++)
        ap[b[i]]--;
    for(i=0;i<=n;i++)
        if(ap[a[i]]||ap[b[i]])
    {
        cout<<"-1";
        return 0;
    }
    for(i=0;i<=n;i++)
        if((!norm[a[i]])&&(a[i]!=b[i]||i==0))
          norm[a[i]]=++nr;
    if(!norm[b[0]])
        norm[b[0]]=++nr;
    for(i=1;i<=n;i++)
        if((a[i]!=b[i]))
    {
        a[i]=norm[a[i]];
        b[i]=norm[b[i]];
        v[a[i]].push_back(b[i]);
        v[b[i]].push_back(a[i]);
        edges++;
    }
    for(int i=1;i<=nr;i++)
        if((!viz[i]))
          dfs(i),cc++;
    cout<<edges+cc-1<<'\n';
    return 0;
}
