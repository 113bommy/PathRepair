#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> P;
#define mp make_pair

map <P,int> ans;

int N, K, L;
int p[200002];
int ran[200002];
int A[200001];
int B[200001];

void init(int n) {
  for(int i = 0; i < n; i++) {
    p[i] = i;
    ran[i] = 0;
  }
}

int Find (int x) {
  if(p[x] == x) return x;
  return p[x] = Find(p[x]);
}

void Union(int x, int y) {
  int a = Find(x);
  int b = Find(y);
  if(a == b) return;
  
  else if(ran[a] > ran[b]) {
    p[a] = b;
  }
  else {
    p[b] = a;
    if(ran[a] == ran[b]) ran[b]++;
  }
  return;
}
    
int main() {
cin >> N >> K >> L;

  init(N);
  
  for(int i = 0; i < K; i++) {
    int p,q;
    cin >> p >> q;
    p--; q--;
    Union(p,q);
  }

  for(int i = 0; i < N; i++) A[i] = Find(i);


  
  init(N);
  
  for(int i = 0; i < L; i++) {
    int r,s;
    cin >> r >> s;
    r--; s--;
    Union(r,s);
  }

  for(int i = 0; i < N; i++) B[i] = Find(i);

  for(int i = 0; i < N; i++) {
    ans[mp(A[i],B[i])]++;
  }

  for(int i = 0; i < N; i++) {
    cout << ans[mp(A[i],B[i])] <<endl;
  }
}
