n=int(input())
a=int(input())
A=[int(x) for x in list(str(a))]
D=list(map(int,input().split()))
Dict={}
for i,d in enumerate(D):
    Dict[i+1]=d
Ans=[]
for i,a in enumerate(A):
    if Dict[a]>a:
        A[i]=Dict[a]
        break
if i<n-1:
    for j,a in enumerate(A[i+1:]):
        if Dict[a]>=a:
            A[j+i+1]=Dict[a]
        else:
            break
print(*A,sep='')