import copy
 
INF = 10000000000
def merge(A, left, mid, right):
    count = 0
    L = A[left:mid] + [(INF,INF)]
    R = A[mid:right] + [(INF,INF)]
     
    i, j = 0, 0
    for k in range(left, right):
        count = count + 1
        if L[i][1] <= R[j][1]:
            A[k] = L[i]
            i = i + 1
        else:
            A[k] = R[j]
            j = j + 1
    return count
 
def mergeSort(A, left, right):
    if left + 1 < right:
        mid = (left + right) // 2
        countL = mergeSort(A, left, mid)
        countR = mergeSort(A, mid, right)
        return merge(A, left, mid, right) + countL + countR
    return 0
def partition(a,p,r):
    x=a[r][1]
    i=p-1
    for j in range(p,r):
        if a[j][1]<=x:
            i+=1
            a[i],a[j]=a[j],a[i]
    a[i+1],a[r]=a[r],a[i+1]
    return i+1
def quickSort(a,p,r):
    if p<r:
        q=partition(a,p,r)
        quickSort(a,p,q-1)
        quickSort(a,q+1,r)
n = int(input())
A = [None for i in range(n)]
for i in range(n):
    a, b = input().split()
    A[i] = (a, int(b))

B = copy.deepcopy(A)
quickSort(A, 0, n-1)
mergeSort(B, 0, n)
if A == B:
    print("Stable")
else:
    print("Not stable")
ans = [str(x[0]) +" "+str(x[1]) for x in A]
ans = '\n'.join(ans)
print(ans)
