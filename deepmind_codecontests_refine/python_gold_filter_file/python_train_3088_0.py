MOD = 10**9+9;

n,a,b,k = map(int,input().split())
s = input();

def pow(a,n,m=MOD):
    ret = 1;
    a %= MOD;
    while n:
        if n&1:
            ret = ret*a%m;
        a = a*a%m;
        n >>= 1;
    return ret;
#def inv(a,p=MOD):
#    return pow(a,p-2,p);
def inv(a,m=MOD):
    if a > 1:
        return (m-m//a*inv(m%a,m))%m;
    return 1

ia,d = inv(a), (n+1)//k
ans, ci0, q = 0, pow(a,n), pow(ia*b,k)
Q = d
if q != 1:
    Q = (pow(q,d)-1)*inv(q-1)%MOD

for i in range(k):
    sign = 1
    if s[i] == '-':
        sign = -1;
    ans += sign*ci0*Q%MOD
    ans %= MOD
    ci0 = ci0*ia*b%MOD
print(ans);
