n=int(input())
c=0
for i in range(n):
    a,b=map(int,input().split())
    if abs(a-b)>=2:
        c+=1
print(c)