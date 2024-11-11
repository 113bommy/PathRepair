a,b=map(int,input().split())
s=list(map(int,input().split()))
q=0
for i in s:
    if i<=b:
        q+=1
    else:
        q+=2
print(q)
