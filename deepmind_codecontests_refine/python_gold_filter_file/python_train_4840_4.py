n=int(input())
A=[]
for i in range(n):
    row=list(map(int,input().strip().split()))
    A.append(row)
arr=[True for i in range(n)]
for i in range(n-1):
    for j in range(i+1,n):
        if A[i][j]==1:
            arr[i]=False
        elif A[i][j]==2:
            arr[j]=False
        elif A[i][j]==3:
            arr[i]=False
            arr[j]=False
l=[]
for i in range(n):
    if arr[i]:
        l.append(i+1)
print(len(l))
print(*l)