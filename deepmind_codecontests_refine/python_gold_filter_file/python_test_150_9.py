import sys,os,io
input = sys.stdin.readline # for strings
# input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline # for non-strings

PI = 3.141592653589793238460
INF =  float('inf')
MOD  = 1000000007
# MOD = 998244353


def bin32(num):
    return '{0:032b}'.format(num)

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

for t in range(ii()):
    t+=1
    n = ii()
    a = li()
    a = list(set(a))    
    a.sort()
    n = len(a)
    flag = 1
    # if t == 74:
    #     print(a)
    cnt = [0 , 0 , 0 ]
    for i in a:
        if i % 3 == 2 and i % 2 != 0:
            flag = 0
        cnt[i%3]+=1
    
    if cnt[0] == n:
        print(a[-1]//3 )
        continue
    if a[-1]%3 == 0:
        print(a[-1]//3 + 1)
        continue

    if cnt[1] == 0 or cnt[2] == 0:
        print(a[-1]//3 + 1)
        continue



    if a[-1] % 3 == 1:
        if 1 in a or a[-1] - 1 in a:
            print(a[-1]//3 + 2)       
        else:
            print(a[-1]//3 + 1)
    else:
        print(a[-1]//3 + 2)
