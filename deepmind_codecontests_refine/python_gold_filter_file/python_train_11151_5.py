def power(x, y, p) : 
    res = 1     # Initialize result 
  
    # Update x if it is more 
    # than or equal to p 
    x = x % p  
      
    if (x == 0) : 
        return 0
  
    while (y > 0) : 
          
        # If y is odd, multiply 
        # x with result 
        if ((y & 1) == 1) : 
            res = (res * x) % p 
  
        # y must be even now 
        y = y >> 1      # y = y/2 
        x = (x * x) % p 
          
    return res 
n,m = list(map(int,input().split()))
a = list(input())
b = list(input())
pre = [0]*max(n+1,m+1)

for i in range(m):
    pre[i] = pre[i-1] + int(b[i])
    
ans = 0
mod = 998244353 

for i in range(n):
    if (a[i]=='1'):
        ans += (pre[i-(n-m)]*power(2,(n-i-1),mod))%mod
        # print((pre[i-(n-m)]*power(2,(n-i-1),mod))%mod,n-i-1)
print(ans%mod)
    