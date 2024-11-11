#include<iostream>
#include<algorithm>
#include<cstdint>
#include<cstdio>
#include<cstdlib>
#include<vector>
template<typename T>
void fin(T const& t){ std::cout << t << std::endl; exit(0); }

uint64_t getZ() {
  uint64_t v = 0; int c;
  while((c = getchar_unlocked()) >= '0') v=v*10+c-'0';
  return v;
}

template<int BUFSIZE>
struct ans_buf {
  char buf[BUFSIZE];
  int i;
  ans_buf(): i(0) {}
  void putZ(uint64_t v, char delim='\n') {
    uint64_t k = 1;
    while(k <= v/10) k*=10;
    for(; k>0; v%=k, k/=10) buf[i++] = (v/k)+'0';
    buf[i++] = delim;
  }
  void out() { std::fwrite(buf, 1, i, stdout); i = 0; }
};

int const MAXN = 500;
int S[MAXN], T[MAXN];
uint64_t U[MAXN], V[MAXN], A[MAXN][MAXN];
int tmp[MAXN][MAXN];

int main() {
  int N = getZ();
  for(int i = 0; i < N; ++i) S[i] = getZ();
  for(int i = 0; i < N; ++i) T[i] = getZ();
  for(int i = 0; i < N; ++i) U[i] = getZ();
  for(int i = 0; i < N; ++i) V[i] = getZ();
  for(int i = 0; i < N; ++i) std::fill_n(A[i], N, (uint64_t)0);
  for(int i = 0; i < 64; ++i) {
    uint64_t b = (uint64_t)1 << i;
    for(int y = 0; y < N; ++y) std::fill_n(tmp[y], N, -1);
    std::vector<int> ux, uy;
    // raw decision (S,U)
    for(int y = 0; y < N; ++y) {
      if((S[y] == 0)==((b&U[y])>0)) for(int x = 0; x < N; ++x) tmp[y][x] = 1 - S[y];
      else uy.push_back(y);
    }
    // column decision (T,V)
    for(int x = 0; x < N; ++x) {
      if((T[x] == 0)==((b&V[x]) > 0)) {
        for(int y = 0; y < N; ++y) {
          if(tmp[y][x] == T[x]) fin(-1);
          tmp[y][x] = 1 - T[x];
        }
      } else ux.push_back(x);
    }
    
    if(ux.size()==0 || uy.size() == 0) {
      // already filled; check
      for(int x: ux) { // every col must have T[x]
        bool ok = false;
        for(int y = 0; y < N; ++y) if(tmp[y][x] == T[x]) ok = true;
        if(!ok) fin(-1);
      }
      for(int y: uy) { // every raw must have S[y]
        bool ok = false;
        for(int x = 0; x < N; ++x) if(tmp[y][x] == S[y]) ok = true;
        if(!ok) fin(-1);
      }
    } else if(ux.size() > 1 && uy.size() > 1) {
      // unfilled >= 2x2: fill like a checkerboard -- no check needed
      for(int iy = 0; iy < uy.size(); ++iy) {
        for(int ix = 0; ix < ux.size(); ++ix) tmp[uy[iy]][ux[ix]] = (ix+iy)%2;
      }
    } else if(ux.size()==1) {
      int x = ux[0]; // the only unfilled column
      // every unfilled raw must have S[y]
      for(int y: uy) {
        bool ok = false;
        for(int xx = 0; xx < N; ++xx) if(xx != x && tmp[y][xx]==S[y]) ok = true;
        if(!ok) tmp[y][x] = S[y];
      }
      // the column must have T[x]
      bool ok = false;
      for(int y = 0; y < N; ++y) {
        if(tmp[y][x]==T[x]) { ok = true; break; }
        if(tmp[y][x] < 0) { tmp[y][x] = T[x]; ok = true; break; }
      }
      if(!ok) fin(-1);
    } else { // uy.size() should == 1
      int y = uy[0]; // the only unfilled raw
      // every unfilled column must have T[x]
      for(int x: ux) {
        bool ok = false;
        for(int yy = 0; yy < N; ++yy) if(yy != y && tmp[yy][x]==T[x]) ok = true;
        if(!ok) tmp[y][x] = T[x];
      }
      // the raw must have S[y];
      bool ok = false;
      for(int x = 0; x < N; ++x) {
        if(tmp[y][x]==S[y]) { ok = true; break; }
        if(tmp[y][x] < 0) { tmp[y][x] = S[y]; ok = true; break; }
      }
      if(!ok) fin(-1);
    }
    
    // copy to A
    for(int y = 0; y < N; ++y) for(int x = 0; x < N; ++x) {
      if(tmp[y][x] > 0) A[y][x] |= b;
    }
  }
  ans_buf<500*21> buf;
  for(int y = 0; y < N; ++y) {
    for(int x = 0; x < N-1; ++x) buf.putZ(A[y][x], ' ');
    buf.putZ(A[y][N-1]);
    buf.out();
  }
  return 0;
}
