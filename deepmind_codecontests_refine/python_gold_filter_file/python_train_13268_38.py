n=int(input())
c=0
for _ in range(n):
    p,q=map(int,input().split())
    if q-p>1:
        c+=1
print(c)