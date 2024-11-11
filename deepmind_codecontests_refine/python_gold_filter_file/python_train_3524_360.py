N=int(input())
a=1
for i in range(1,N+1):
    a=(a*i)%((10**9)+7)
print(a)