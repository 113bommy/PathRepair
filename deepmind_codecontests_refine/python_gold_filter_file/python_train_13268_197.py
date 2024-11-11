n=int(input())
c=0
for i in range(n):
    p,q=list(map(int,input().split()))
    if(q-p>1):
        c+=1
print(c)