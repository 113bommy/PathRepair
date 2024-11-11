def function(arr,n):
    s=0
    for i in range(n-1):
        if arr[i+1]<arr[i]:
            s+=1
            break
    if s==1:
        return False
    return True
def anotherFunction(arr,n):
    lis=[0]*(n+1)
    for i in range(n):
        lis[arr[i]]=1
    a=lis.count(1)
    if (lis[-1]==0 or lis[-2]==0) and a==n:
        if arr[-1]==n or arr[-1]==n-1:
            return True
        return False
    return False
def impFunction(arr,n):
    for i in range(n):
        if arr[i]!=i:
            return i
def MEX(arr,n):
    lis=[0]*(n+1)
    for i in range(n):
        lis[arr[i]]=1
    for i in range(n+1):
        if lis[i]==0:
            return i
t=int(input())
for i in range(t):
    n=int(input())
    arr=list(map(int,input().split()))
    ans=[]
    for j in range(2*n):
        b=function(arr,n)
        c=anotherFunction(arr,n)
        if b==True:
            break
        elif c==True:
            d=impFunction(arr,n)
            a=MEX(arr,n)
            arr[d]=a
            ans.append(d+1)
        else:
            a=MEX(arr,n)
            if a!=n:
                arr[a]=a
                ans.append(a+1)
            else:
                arr[a-1]=a
                ans.append(a)
    print(len(ans))
    print(" ".join(str(x) for x in ans))
            