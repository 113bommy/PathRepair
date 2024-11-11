
n=int(input())

A=list(map(int,input().split()))
        
A.sort(reverse=True)

X=[]

t=-1

for i in A:
    if t==i:
        t=-1
        X.append(i)
        if len(X)>1:
            break
    else:
        t=i
        
if len(X)>1:
    print(X[0]*X[1])
else:
    print(0)