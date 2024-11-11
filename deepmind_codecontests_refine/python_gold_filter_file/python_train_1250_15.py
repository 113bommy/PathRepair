def Partition(A,p,r):
    x = A[r]
    i = p-1
    for j in range(p,r):
        if (A[j] <= x):
            i += 1
            A[i],A[j] = A[j],A[i]
    A[i+1],A[r] = A[r],A[i+1]
    return i+1

n = int(input())
st = input()
data = list(map(int,st.split()))

mid = Partition(data,0,len(data)-1)
for i in range(0,mid):
    print(data[i],end=" ")
print("[{0}] ".format(data[mid]),end="")
for i in range(mid+1,len(data)-1):
    print(data[i],end=" ")
print(data[len(data)-1])