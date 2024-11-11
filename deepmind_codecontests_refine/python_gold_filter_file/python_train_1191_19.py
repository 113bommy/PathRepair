def sort(n,a):
    min=0
    max=n-1
    for i in range(n-1):
        if a[i]>a[i+1]:
            min=i
            for j in range(i+1,n):
                if a[j]>a[min]:
                    max=j-1
                    break
            break
    if min==0 and max==n-1:
        if sorted(a)==a:
            print("yes")
            print(1,1)
        elif sorted(a)==a[::-1]:
            print("yes")
            print(min+1,max+1)
        else:
            print("no")
    elif min==0:
        k=a[min:max+1][::-1]+a[max+1:]
        if sorted(a)==k:
            print("yes")
            print(min+1,max+1)
        else:
            print("no")
    elif max==n-1:
        k=a[0:min]+a[min:][::-1]
        if sorted(a)==k:
            print("yes")
            print(min+1,max+1)
        else:
            print("no")
    else:
        k=a[0:min]+a[min:max+1][::-1]+a[max+1:]
        if sorted(a)==k:
           print("yes")
           print(min+1,max+1)
        else:
           print("no")
    
n=int(input())
a=list(map(int,input().split()))
sort(n,a)
    