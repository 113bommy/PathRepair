mod = 10**9+7;
n = int(input())
x = 1;
for i in range(2, n+1):x = (x*i%mod)
print((x-(2**(n-1)))%mod)
