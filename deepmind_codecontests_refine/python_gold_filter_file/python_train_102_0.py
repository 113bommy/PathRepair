i=input
N=int(i())
A=list(map(int,i().split()))
r = range
c=0
for i in r(N):
    minj=i
    for j in r(i,N):
        if A[j] < A[minj]:
            minj = j
    if i !=minj:
        c+=1
    A[i],A[minj] = A[minj],A[i]
print(*A)
print(c)