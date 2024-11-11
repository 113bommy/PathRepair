N=int(input())
p=1
for i in range(1,N+1):
    p=p*i%(10**9+7)
print(p)