import sys
import math
def gcd(a, b):
    	c = max(a,b)
    	d = min(a,b)
    	r = c%d
    	if r==0:
    		return d
    	return gcd(d,r)
    	
def lcm(a, b):
    def gcd_naive(a, b):
    	c = max(a,b)
    	d = min(a,b)
    	r = c%d
    	if r==0:
    		return d
    	return gcd_naive(d,r)

    return int(a*b/gcd_naive(a,b))

def fn(n,k):
    l=[0]*(n)
    if n<=k:
        print(-1)
        return 0
    elif n==k+1:
        for i in range(n):
            l[i]=i+1
        print(*l)
        return 0
    else:
        for i in range(1,k+1):
            l[i]=i+1
        l[0]=n
        for i in range(n-2,k,-1):
            l[i+1]=i+1
        l[k+1]=1
        print(*l)
        
    
    
if __name__ == '__main__':    
    input = sys.stdin.read()
    data = list(map(int, input.split()))
    n = data[0]
    k = data[1]
    (fn(n,k))