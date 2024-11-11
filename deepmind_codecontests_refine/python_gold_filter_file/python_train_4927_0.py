for _ in range(int(input())):
    n=int(input())
    a=list(map(int,input().split()))
    arr=[10e6]*(2*n+1)
    for i in range(n):
        arr[a[i]]=i+1
    ct=0
    for i in range(3,2*n):
        for j in range(1,int(i**(0.5))+1):
            if(i%j==0 and i!=j**2):
                if(arr[j]+arr[i//j]==i):
                    ct+=1
    print(ct)