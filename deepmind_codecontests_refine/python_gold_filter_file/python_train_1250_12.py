def partition(A,p,r):
    x = A[r]
    i = p
    for j in range(p,r):
        if A[j] <= x:
            A[j],A[i] = A[i],A[j]
            i += 1
    A[r],A[i] = A[i],A[r]
    return i

n = int(input())
A = list(map(int,input().split()))
i = partition(A,0,n-1)
A[i] = "[{}]".format(A[i])
print(*A)