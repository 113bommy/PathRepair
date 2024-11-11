n=int(input())
p=1
for c in range(1,n+1):
    p=(p*c)%(10**9+7)
print(p)