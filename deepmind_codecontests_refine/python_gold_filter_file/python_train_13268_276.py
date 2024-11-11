n=int(input())
c=0
for _ in range(n):
    a,b=map(int,input().split())
    if (b-a)>=2:
        c+=1
print(c)