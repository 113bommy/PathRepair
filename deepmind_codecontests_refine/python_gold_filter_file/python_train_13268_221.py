t=int(input())
c=0
for h in range(t):
    p,q=list(map(int,input().split()))
    if(q-p>1):
        c+=1
print(c)