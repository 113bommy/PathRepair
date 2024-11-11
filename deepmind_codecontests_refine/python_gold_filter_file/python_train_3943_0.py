#互いに素なa,bについて、a*x+b*y=1の一つの解
def extgcd(a,b):
    r = [1,0,a]
    w = [0,1,b]
    while w[2]!=1:
        q = r[2]//w[2]
        r2 = w
        w2 = [r[0]-q*w[0],r[1]-q*w[1],r[2]-q*w[2]]
        r = r2
        w = w2
    #[x,y]
    return [w[0],w[1]]

# aの逆元(mod m)を求める。(aとmは互いに素であることが前提)
def mod_inv(a,m):
    x = extgcd(a,m)[0]
    return (m+x%m)%m

#n! = a p^eとしたときのeを求める (O(logp n)
def mod_e(n,p):
    res = 0
    while n >= p:
        res += n//p
        n = n//p
    return res

#n! = a p^eとしたときのa mod pを求める  (O(logp n)
def mod_fact(n,p):
    if n==0:
        return 1
    
    
    res = mod_fact(n//p,p)
    
    if n//p %2 != 0:
        return res*(p-fact[n%p])%p
    return res*fact[n%p]%p
    
######################################################

#nCk mod p
def mod_comb(n,k):
    if n < 0 or k < 0 or n<k:
        return 0
    e1 = mod_e(n,p)
    e2 = mod_e(k,p)
    e3 = mod_e(n-k,p)
    #pで割り切れる場合
    if e1 > e2 + e3:
        return 0

    #pで割り切れない場合
    a1 = mod_fact(n,p)
    a2 = mod_fact(k,p)
    a3 = mod_fact(n-k,p)
    return a1 * mod_inv(a2*a3%p,p) %p
######################################################

h,w,a,b = map(int,input().split())
#pは素数とする
p = 10**9+7
#fact[i] : i! modp (0<= i <p) O(p)
fact = [1]
k = 1
for i in range(1,10**6+10):
    k = k*i%p
    fact.append(k)

res = 0
for i in range(h-a):
    res += mod_comb(i+b-1,b-1)*mod_comb(h-i-1+w-b-1,w-b-1)
    res = res%p
print(res)