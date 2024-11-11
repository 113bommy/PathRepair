PI = 3.141592653589793238460
INF =  999999999
MOD  = 1000000007
# MOD = 998244353

def add(x,y):
    return (x+y)%MOD

def sub(x,y):
    return (x-y+MOD)%MOD

def mul(x,y):
    return (x*y)%MOD

def gcd(x,y):
    if y == 0:
        return x
    return gcd(y,x%y)

def lcm(x,y):
    return (x*y)//gcd(x,y)

def power(x,y):
    res = 1
    x%=MOD
    while y!=0:
        if y&1 :
            res = mul(res,x)
        y>>=1
        x = mul(x,x)
        
    return res
        
def mod_inv(n):
    return power(n,MOD-2)

def prob(p,q):
    return mul(p,power(q,MOD-2))    
  
def ii():
    return int(input())

def li():
    return [int(i) for i in input().split()]

def ls():
    return [i for i in input().split()]

store = [6**i for i in range(30)]
s2 = [2**i for i in range(30)]
# print(store)

for t in range(ii()):
    n = ii()
    # if n %3 != 0:
    #     if n == 1:
    #         print(0)
    #     else:
    #         print(-1)
    #     continue
    ans = -1
    for i in range(30):
        temp = n*s2[i]
        for j in range(30):
            if temp == store[j] :
                #print(s2[i],store[j]," --- ")
                ans = i+ j
                break
        if ans !=-1:
            break
    print(ans)
                



    

 