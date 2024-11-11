#define _USE_MATH_DEFINES
#include <cstdio>
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <complex>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <bitset>
#include <numeric>
#include <limits>
#include <climits>
#include <cfloat>
#include <functional>
#include <iterator>
using namespace std;

template <class T1>
class Operators
{
public:
    template <class T2>
    const T1 operator+(const T2& right) const{
        T1 ans = static_cast<const T1&>( *this );
        ans += right;
        return ans;
    }
    template <class T2>
    const T1 operator-(const T2& right) const{
        T1 ans = static_cast<const T1&>( *this );
        ans -= right;
        return ans;
    }
    template <class T2>
    const T1 operator*(const T2& right) const{
        T1 ans = static_cast<const T1&>( *this );
        ans *= right;
        return ans;
    }
    template <class T2>
    const T1 operator/(const T2& right) const{
        T1 ans = static_cast<const T1&>( *this );
        ans /= right;
        return ans;
    }
    bool operator!=(const T1& right) const{
        const T1& left = static_cast<const T1&>( *this );
        return !(left == right);
    }
};

class Fraction
{
private:
    long long n; // ?????????numerator???
    long long d; // ?????????denominator???

    // ?´????
    void reduce(){
        if(d < 0){
            n *= -1;
            d *= -1;
        }
        long long a = abs(n);
        long long b = d;
        while(b != 0){
            long long tmp = a % b;
            a = b;
            b = tmp;
        }
        n /= a;
        d /= a;
    }
public:
    Fraction(){
        n = 0;
        d = 1;
    }
    Fraction(long long n0){
        n = n0;
        d = 1;
    }
    Fraction(long long n0, long long d0){
        n = n0;
        d = d0;
        reduce();
    }
    pair<long long, long long> getValue() const{
        return make_pair(n, d);
    }
    Fraction& operator+=(const Fraction& f){
        n = n * f.d + d * f.n;
        d *= f.d;
        reduce();
        return *this;
    }
    Fraction& operator-=(const Fraction& f){
        n = n * f.d - d * f.n;
        d *= f.d;
        reduce();
        return *this;
    }
    Fraction& operator*=(const Fraction& f){
        n *= f.n;
        d *= f.d;
        reduce();
        return *this;
    }
    Fraction& operator/=(const Fraction& f){
        n *= f.d;
        d *= f.n;
        reduce();
        return *this;
    }
    bool operator==(const Fraction& f) const{
        return n == f.n && d == f.d;
    }
};

int main()
{
    string s;
    cin >> s;
    int n = s.size();
    int i = s.find('.');
    int j = s.find('(');
    if(j == string::npos)
        j = n;

    string s1 = s.substr(0, i);
    Fraction ans(stoll(s1));
    
    string s2 = s.substr(i+1, j-i-1);
    long long base = stoll('1' + string(s2.size(), '0'));
    if(!s2.empty())
        ans += Fraction(stoll(s2), base);

    if(j < n){
        string s3 = s.substr(j+1, n-j-2);
        base *= stoll(string(s3.size(), '9'));
        ans += Fraction(stoll(s3), base);
    }

    auto& p = ans.getValue();
    cout << p.first << '/' << p.second << endl;

    return 0;
}