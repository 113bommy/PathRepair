t=int(input())
c=0
for k in range(t):
    m,n=map(int,input().split())
    if n-m>=2:
        c+=1
print(c)