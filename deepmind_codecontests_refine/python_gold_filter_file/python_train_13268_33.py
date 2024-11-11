x=int(input())
c=0
for i in range(x):
    a,b=map(int,input().split())
    if b-a>=2:
        c+=1
print(c)