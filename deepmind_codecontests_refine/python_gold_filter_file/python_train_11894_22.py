def arr(n):
    l=[]
    e=2
    o=1
    c=0
    while c<n:
        i=0
        while e<=n and i<2:
            l.append(e)
            e+=2
            i+=1
            c+=1
        j=0
        while o<=n and j<2:
            l.append(o)
            o+=2
            j+=1
            c+=1
    return l

t=int(input())
for w in range(t):
    n=int(input())
    if n<=3:
        print(-1)
    elif n%4==0 or (n+3)%4==0:
        print(*arr(n))
    elif n%2==0:
        arr1=arr(n)
        arr1[n-1],arr1[n-3]=arr1[n-3],arr1[n-1]
        arr1[n-1],arr1[n-2]=arr1[n-2],arr1[n-1]
        print(*arr1)
    else:
        arr1=arr(n)
        arr2=arr1[0:n-6]
        arr2.append(arr1[n-3])
        arr2=arr2+arr1[(n-6):(n-3)]
        arr2=arr2+arr1[(n-2):]
        print(*arr2)
