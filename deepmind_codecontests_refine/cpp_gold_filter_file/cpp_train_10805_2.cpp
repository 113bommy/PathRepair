


#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;


const int MAXN = 1005;

int main() {
  int n;
  cin>>n;
  deque<int> a[n];
  rep(i,n)rep(j,n-1){
    int temp;
    cin>>temp;
    temp--;
    a[i].push_back(temp);
  }
  vector<P>q;
  auto check=[&](int i){
    if (a[i].size()==0)return;
    int j=a[i].front();
    if (a[j].front()==i){
      if (i>j)swap(i,j);
      q.push_back(make_pair(i,j));
    }
  };

  int ans=0;
  rep(i,n){
    check(i);
  }
  while (q.size()>0){
    ans++;
    sort(q.begin(),q.end());
    q.erase(unique(q.begin(),q.end()),q.end());
    vector<P>prev;
    swap(q,prev);
    for(P p : prev){
      int f=p.first;
      int s=p.second;
      a[f].pop_front();
      a[s].pop_front();

    }
    for(P p : prev){
      check(p.first);
      check(p.second);
  }
}
rep(i,n){
  if (a[i].size()>0) ans=-1;
}
 cout<<ans;




}
