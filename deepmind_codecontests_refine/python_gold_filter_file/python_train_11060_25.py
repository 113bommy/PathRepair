t=int(input())
for i in range(t):
    n=int(input())
    a=[]
    if (n%4)!=0:
        print("NO")
    else:
        for i in range(1,n//2+1):
            a.append(2*i)
        #print(a)
        for i in range(1,n//2+1):
            a.append(2*i-1)
        #print(a)
        a[n-1]=a[n-1]+n//2
        print("YES")
        print(*a)
        
    