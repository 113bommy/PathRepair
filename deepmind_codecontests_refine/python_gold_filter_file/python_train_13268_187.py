t=int(input())
c=0
for _ in range(t):
    a,b=map(int,input().split())
    if abs(a-b)>=2:
        c+=1
print(c)