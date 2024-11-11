n,m = map(int,input().split())
A = list(map(int,input().split()))
D = [];prev = []
if(A[0]<m):
    D.append(0)
    prev.append(m-A[0])
else:
    D.append(A[0]//m)
    prev.append(m-A[0]%m)
i = A[0]//m
j=1
while(j<n):
    if(A[j]<prev[-1]):
        D.append(0)
        prev.append(prev[-1]-A[j])
    else:
        A[j]-=prev[-1]
        D.append(A[j]//m+(prev[-1]!=0))
        prev.append(m-A[j]%m)
        i+=A[j]//m+1
    j+=1
print(*D)
    
