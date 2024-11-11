t=int(input())
c=0
for i in range(0,t):
    l=list(map(int,input().rstrip().split()))
    a=l.count(1)
    if a>=2:
        c+=1
print(c)
