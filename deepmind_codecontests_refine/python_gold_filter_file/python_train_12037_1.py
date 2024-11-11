n,x=map(int,input().split())
arr=list(map(int,input().split()))
arr.append(-1)
arr=sorted(arr)
if x<arr[1]:
    print(x)
elif x>arr[n]:
    print(x-n)
else:
    s=0
    for i in range(1,n+1):
        s+=arr[i]-arr[i-1]-1
        if x==arr[i]:
            print(s+1)
            exit(0)
        elif x<arr[i] and x>arr[i-1]:
            print(s-(arr[i]-x))
            exit(0)