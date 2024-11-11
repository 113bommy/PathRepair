#include <bits/stdc++.h>

using namespace std;

using ll = long long;

template<int MOD>
struct ModInt {
   using Mint = ModInt;
   int val;
   ModInt(ll __val = 0) { fix(__val % MOD + MOD); }
   Mint& fix(int __val) { val = __val; if (val >= MOD) val -= MOD; return *this; }
   explicit operator int() { return val; }
   Mint operator + (const Mint &mt) const { return Mint().fix(val + mt.val); }
   Mint operator - (const Mint &mt) const { return Mint().fix(val - mt.val + MOD); }
   Mint operator * (const Mint &mt) const { return Mint().fix(ll(val) * mt.val % MOD + MOD); }
   Mint& operator += (const Mint &mt) { return *this = *this + mt; }
   Mint& operator -= (const Mint &mt) { return *this = *this - mt; }
   Mint& operator *= (const Mint &mt) { return *this = *this * mt; }
   Mint pow(int y) const {
      Mint x = *this;
      Mint ans(1);
      for (; y > 0; y >>= 1, x *= x) {
         if (y & 1) ans *= x;
      }
      return ans;
   }
   Mint operator -() const { return Mint().fix(MOD - val); }
   Mint inv() const { return pow(MOD - 2); }
   Mint operator / (const Mint &mt) const { return *this * mt.inv(); }
   Mint& operator /= (const Mint &mt) const { return *this / mt; }
   friend ostream& operator<<(ostream& os, const Mint& mt) { return os << mt.val; }
};

using Mint = ModInt<1000000007>;

int main() {
   ios_base::sync_with_stdio(false); cin.tie(nullptr);
   int N, M;
   cin >> N >> M;
   vector<Mint> dp(M + 1);
   dp[M] = 1;
   for (int b = N - 1; b >= 0; --b) {
      vector<Mint> ndp(M + 1);
      Mint tot = 0;
      for (int i = M; i >= 0; --i) {
         ndp[i] = dp[i] * (i + 1) + tot * i;
         tot = tot + tot + dp[i];
      }
      dp = move(ndp);
   }
   Mint ans = 0;
   for (auto v : dp) ans += v;
   cout << ans << "\n";
   return 0;
}
