n,x = [int(i) for i in input().split()]
a = [i for i in range(1,2*n)]

def swap(a,i,j):
    b = a[i]
    a[i] = a[j]
    a[j] = b

if x==1 or x==2*n -1:
    print("No")
else:
    print("Yes")
    if x==n:
        pass
    elif x>n:
        swap(a,n-1,x-1)
        swap(a,n,2*n-2)
        swap(a,n+1,0)
    else:
        swap(a,n-1,x-1)
        swap(a,n-2,0)
        swap(a,n-3,2*n-2)
    for i in a:
        print(i)