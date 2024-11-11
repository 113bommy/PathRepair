#include<bits/stdc++.h>
using namespace std;
#define pt pair<double,double>
#define x first
#define y second
const double INF=1e7;
pt p[100010];
double dist(pt a,pt b)
{return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));}
bool cmpy(pt a,pt b){return a.y<b.y;}
double closest(int l,int r)
{
  if(l==r) return INF;
  int mid=(l+r)/2,pp=l,qq=mid+1;
  double midline=p[mid].x;
  double ret=min(closest(l,mid),closest(mid+1,r));
  vector<pt> slab;
  inplace_merge(p+l,p+mid+1,p+r+1,cmp);
  for(int i=l;i<=r;i++)
    if(abs(p[i].x-midline)<ret)
      slab.push_back(p[i]);
  for(int i=0;i<slab.size();i++)
    for(int j=i+1;j<slab.size() && abs(slab[i].y-slab[j].y)<ret;j++)
      ret=min(ret,dist(slab[i],slab[j]));
  return ret;
}
int main()
{
  int n;
  cin>>n;
  for(int i=1;i<=n;i++)
    cin>>p[i].x>>p[i].y;
  sort(p+1,p+n+1);
  cout<<fixed<<closest(1,n)<<endl;
  return 0;
}