n,k=map(int,input().split())
arr=list(input())
lenght=len(arr)
for i in range(lenght):
    arr[i]=int(arr[i])
if lenght==1 and k==1:
    print("0")
elif lenght==1 and k==0:
    print(arr[0])
elif lenght>1 and k<=lenght:
    for i in range(lenght):
        if arr[i]>1 and k>0 and i==0:
            arr[0]=1 
            k-=1
        elif arr[i]>=1 and k>0 and i>0:
            arr[i]=0
            k-=1
        else:
            pass
    for i in range(lenght):
        print(arr[i],end="")    
else:
    pass