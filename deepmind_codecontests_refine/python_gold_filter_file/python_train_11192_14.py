def b_s(arr,target):
    start=0
    end=len(arr)-1
    mid=(start+end)//2
    while start<=end:
        if arr[mid]>target:
            end=mid-1
            mid=(start+end)//2
        else:
            start=mid+1
            mid=(start+end)//2
    return mid+1

n,m=[int(num) for num in input().split()]
A=[int(nu) for nu in input().split()]
B=[int(nu) for nu in input().split()]
A.sort()
for i,j in enumerate(B):
    if i<m-1:
        if j < A[0]:
            print(0,end=" ")
        elif j >= A[-1]:
            print(n, end=' ')
        else:
            print(b_s(A, j), end=' ')
    else:
        if j < A[0]:
            print(0,end="")
        elif j >= A[-1]:
            print(n, end='')
        else:
            print(b_s(A, j), end='')

