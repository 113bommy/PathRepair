n=int(input())
c=0
for i in range(n):
    f,s=map(int,input().split())
    if (s-f)>=2:
        c+=1
print(c)
