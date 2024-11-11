def Match(p,q,a,b):
    if(q<a or p>b):
        return -1
    else:
        return (max(a,p), min(b,q))
    
m,x = map(int,input().split())
p = 0
q = 1000
flag = 0
for i in range(m):
    a,b = map(int,input().split())
    a,b = min(a,b), max(a,b)
    X = Match(p,q,a,b)
    if(X==-1):
        print(-1)
        flag = 1
        break
    else:
        p,q = X
if(not flag):
    if(p>x):
        print(p-x)
    elif(q<x):
        print(x-q)
    else:
        print(0)