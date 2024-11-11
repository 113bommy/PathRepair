import math

def divisorGenerator(n):
    large_divisors = []
    for i in range(1, int(math.sqrt(n) + 1)):
        if n % i == 0:
            yield i
            if i*i != n:
                large_divisors.append(n / i)
    for divisor in reversed(large_divisors):
        yield divisor


    
        
def result(n,k):
    Main = []
    Last = n
    for i in range(1,n*2):
        if k==1:
            break
        Main.append(i)
        Last -= i
        k -= 1
    Main.append(Last)
    return Main
    
n,k = map(int,input().split())
divisors = list(divisorGenerator(n))
for i in range(len(divisors)):
    divisors[i] = int(divisors[i])
    
kk = (k**2+k)//2
if n<kk:
    print(-1)
else:
    oo = n//(kk)
    pp = 1
    for i in divisors:
        if i <= oo:
            pp = i
    oo = pp
    w = result(n//oo,k)
    s = ""
    for i in w:
        s += " "+str(i*oo)
    print(s[1:])
            
    
        
            
                
    
