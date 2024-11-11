x,t,a,b,da,db=map(int,input().split())
q,w=[0],[0]
for i in range(t):
    q+=[a]
    a-=da
for i in range(t):
    w+=[b]
    b-=db
for i in q:
    for j in w:
        if i+j==x:
            exit(print("YES"))
print("NO")