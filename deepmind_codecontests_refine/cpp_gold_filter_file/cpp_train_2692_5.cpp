#include <bits/stdc++.h>

using namespace std;

int N,K,L;
int p[200001];
int Rank[200001];
map <pair<int,int>,int> ans;
int a[200001];
int b[200001];

void init() {
  for(int i = 0; i < N; i++) {
    p[i] = i;
    Rank[i] = 0;
  }
}

int Find (int x) {
  if(p[x] == x) return x;
  return p[x] = Find(p[x]);
}

void Union (int a, int b) {
  int x = Find(a);
  int y = Find(b);
  if(x == y) return;
  else {
    if(Rank[x] > Rank[y]) p[y] = x;
    else p[x] = y;
    if(Rank[x] == Rank[y]) Rank[x]++;
  }
}
    
    
    
  

int main () {
  cin >> N >> K >> L;

  init();
  for(int i = 0; i < K; i++){
    int a,b;
    cin >> a >> b;
    a--; b--;
    Union(a,b);
  }

  for(int i = 0; i < N; i++) a[i] = Find(i);

  init();

  for(int i = 0; i < L; i++) {
    int a,b;
    cin >> a >> b;
    a--; b--;
    Union(a,b);
  }

  for(int i = 0; i < N; i++) b[i] = Find(i);
 
  
  for(int i = 0; i < N; i++)  ans[make_pair(a[i],b[i])]++;

  for(int i = 0; i < N; i++)
    cout << ans[make_pair(a[i],b[i])] <<endl;
}
  

  
