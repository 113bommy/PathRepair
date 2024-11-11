import math
def prime(n):
    ok= True
    for i in range(2, int(math.sqrt(n))):
        if(n%i==0):
            ok = False
            break
    if(ok):
        return True
    else:
        return False
def primefacts(n):
    ans = []
    while(n%2==0):
        ans.append(2)
        n//=2
    for i in range(3, int(math.sqrt(n))+1, 2):
        if(n%i==0):
            while(n%i==0):
                ans.append(i)
                n//=i
    if(n!= 1):
        ans.append(n)
    return sorted(ans)
def fact(a,b):
    ans = 1
    for i in range(a, b+1):
        ans*= i
    return str(ans)-1
def comb(n, c):
    return fact(n)//(fact(n-c)*c)

n, k = map(int, input().split())
fac = primefacts(n)
if(prime(n) and k==1):
    print(n)
elif(int(math.sqrt(n))**2==n and k==2):
    print(int(math.sqrt(n)), int(math.sqrt(n)))
elif(len(fac)<k):
    print(-1)
else:
    ans = []
    cnt = 0
    for i in range(len(fac)-k):
        fac[-1]*= fac[cnt]
        fac[cnt] = ''
        cnt+=1
    for i in range(len(fac)):
        if(fac[i]!= ''):
            ans.append(str(fac[i]))
    print(' '.join(ans))