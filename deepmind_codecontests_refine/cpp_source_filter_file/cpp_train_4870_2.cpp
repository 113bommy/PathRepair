#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr long long MOD = (long long)1e9 + 7;

template <class T, class U>ostream &operator<<(ostream &o, const map<T, U>&obj) {o << "{"; for (auto &x : obj) o << " {" << x.first << " : " << x.second << "}" << ","; o << " }"; return o;}
template <class T>ostream &operator<<(ostream &o, const set<T>&obj) {o << "{"; for (auto itr = obj.begin(); itr != obj.end(); ++itr) o << (itr != obj.begin() ? ", " : "") << *itr; o << "}"; return o;}
template <class T>ostream &operator<<(ostream &o, const multiset<T>&obj) {o << "{"; for (auto itr = obj.begin(); itr != obj.end(); ++itr) o << (itr != obj.begin() ? ", " : "") << *itr; o << "}"; return o;}
template <class T>ostream &operator<<(ostream &o, const vector<T>&obj) {o << "{"; for (int i = 0; i < (int)obj.size(); ++i)o << (i > 0 ? ", " : "") << obj[i]; o << "}"; return o;}
template <class T, class U>ostream &operator<<(ostream &o, const pair<T, U>&obj) {o << "{" << obj.first << ", " << obj.second << "}"; return o;}
void print(void) {cout << endl;}
template <class Head> void print(Head&& head) {cout << head;print();}
template <class Head, class... Tail> void print(Head&& head, Tail&&... tail) {cout << head << " ";print(forward<Tail>(tail)...);}

/*
 * @title ModInt
 */
template<long long mod> class ModInt {
public:
    long long x;
    constexpr ModInt():x(0) {}
    constexpr ModInt(long long y) : x(y>=0?(y%mod): (mod - (-y)%mod)%mod) {}
    ModInt &operator+=(const ModInt &p) {if((x += p.x) >= mod) x -= mod;return *this;}
    ModInt &operator+=(const long long y) {ModInt p(y);if((x += p.x) >= mod) x -= mod;return *this;}
    ModInt &operator+=(const int y) {ModInt p(y);if((x += p.x) >= mod) x -= mod;return *this;}
    ModInt &operator-=(const ModInt &p) {if((x += mod - p.x) >= mod) x -= mod;return *this;}
    ModInt &operator-=(const long long y) {ModInt p(y);if((x += mod - p.x) >= mod) x -= mod;return *this;}
    ModInt &operator-=(const int y) {ModInt p(y);if((x += mod - p.x) >= mod) x -= mod;return *this;}
    ModInt &operator*=(const ModInt &p) {x = (x * p.x % mod);return *this;}
    ModInt &operator*=(const long long y) {ModInt p(y);x = (x * p.x % mod);return *this;}
    ModInt &operator*=(const int y) {ModInt p(y);x = (x * p.x % mod);return *this;}
    ModInt &operator^=(const ModInt &p) {x = (x ^ p.x) % mod;return *this;}
    ModInt &operator^=(const long long y) {ModInt p(y);x = (x ^ p.x) % mod;return *this;}
    ModInt &operator^=(const int y) {ModInt p(y);x = (x ^ p.x) % mod;return *this;}
    ModInt &operator/=(const ModInt &p) {*this *= p.inv();return *this;}
    ModInt &operator/=(const long long y) {ModInt p(y);*this *= p.inv();return *this;}
    ModInt &operator/=(const int y) {ModInt p(y);*this *= p.inv();return *this;}
    ModInt operator=(const int y) {ModInt p(y);*this = p;return *this;}
    ModInt operator=(const long long y) {ModInt p(y);*this = p;return *this;}
    ModInt operator-() const {return ModInt(-x); }
    ModInt operator++() {x++;if(x>=mod) x-=mod;return *this;}
    ModInt operator--() {x--;if(x<0) x+=mod;return *this;}
    ModInt operator+(const ModInt &p) const { return ModInt(*this) += p; }
    ModInt operator-(const ModInt &p) const { return ModInt(*this) -= p; }
    ModInt operator*(const ModInt &p) const { return ModInt(*this) *= p; }
    ModInt operator/(const ModInt &p) const { return ModInt(*this) /= p; }
    ModInt operator^(const ModInt &p) const { return ModInt(*this) ^= p; }
    bool operator==(const ModInt &p) const { return x == p.x; }
    bool operator!=(const ModInt &p) const { return x != p.x; }
    ModInt inv() const {int a=x,b=mod,u=1,v=0,t;while(b > 0) {t = a / b;swap(a -= t * b, b);swap(u -= t * v, v);} return ModInt(u);}
    ModInt pow(long long n) const {ModInt ret(1), mul(x);for(;n > 0;mul *= mul,n >>= 1) if(n & 1) ret *= mul;return ret;}
    friend ostream &operator<<(ostream &os, const ModInt &p) {return os << p.x;}
    friend istream &operator>>(istream &is, ModInt &a) {long long t;is >> t;a = ModInt<mod>(t);return (is);}
};

template<long long mod> class FormalPowerSeries{
    using Mint = ModInt<mod>;
    using Fps  = FormalPowerSeries<mod>;
    vector<Mint> ar;
    Fps even(void) const {Fps ret;for(int i = 0; i < this->size(); i+=2) ret.push_back((*this)[i]);return ret;}
    Fps odd(void)  const {Fps ret;for(int i = 1; i < this->size(); i+=2) ret.push_back((*this)[i]);return ret;}
public:
    //a0 + a_1*x^1 + a_2*x^2 + ... + a_(n-1)*x^(n-1) + a_n*x^n
    FormalPowerSeries(){}
    FormalPowerSeries(int n):ar(n+1,0){}
    FormalPowerSeries(int n,Mint a):ar(n+1,a){}
    FormalPowerSeries(const vector<Mint>& v):ar(v){}
    FormalPowerSeries(initializer_list<Mint> v):ar(v){}
    size_t size(void) const {return ar.size();}
    size_t dimension(void) const {return ar.size()-1;}
    Mint& operator[](size_t i) {return ar[i];}
    Mint operator[](size_t i) const {return ar[i];}
    void push_back(Mint a){ar.push_back(a);}
    void pop_back(void){ar.pop_back();}
    Fps operator*(const Fps& r) const { return Fps(*this) *= r; }
    Fps &operator*=(const Fps& r) {Fps ret((this->dimension())+r.dimension);for(int i=0;i<(this->size());++i) for(int j=0;j<r.size();++j) ret[i+j]+=((*this)[i])*r[j];return *this = ret;}
    Fps pow(long long n) const {Fps ret(0,1), mul(*this);for(;n > 0;mul *= mul,n >>= 1LL) if(n & 1LL) ret *= mul;return ret;}
    Fps minus_x(void) const {Fps ret(this->dimension);for(int i = 0; i < ret.size(); ++i) ret[i] = (*this)[i]*(i&1?-1:1);return ret;}
    friend ostream &operator<<(ostream &os, const Fps& fps) {os << "{" << fps[0];for(int i=1;i<fps.size();++i) os << ", " << fps[i];return os << "}";}

    /**
     * O(log(n)*d*d)
     * fpsのn項目のみを求める。
     * @param n 求めたい項数
     * @param numerator 分子のfps
     * @param denominator 分母のfps
     * @see <a href="http://q.c.titech.ac.jp/docs/progs/polynomial_division.html">線形漸化式を満たす数列のN項目を計算するアルゴリズム</a>
     */
    static Mint nth_term(long long n, Fps numerator,Fps denominator) {
        while(n) {
            numerator   *= denominator.minus_x();
            if(n&1) numerator = numerator.odd();
            else    numerator = numerator.even();
            denominator *= denominator.minus_x();
            denominator  = denominator.even();
            n >>= 1;
        }
        return numerator[0];
    }
};
using fps = FormalPowerSeries<MOD>;

int main() {
    int Q; cin >> Q;
    fps f0({0,1}),f1({1,-1}),f2({1,1}),nu,de;
    nu = f0.pow(5);
    de = f1.pow(16)*f2.pow(5);
    while(Q--) {
        long long N; cin >> N;
        cout << fps::nth_term(N,nu,de) << "\n";
    }
    return 0;
}