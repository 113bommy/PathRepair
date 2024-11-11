test=int(input())
for i in range(0,test):
    a=input()
    arr=list(map(int,input().split()))
    brr=[]
    for i in range(1,len(arr)-1):
        if(arr[i]==-1):
            brr.append(arr[i-1])
            brr.append(arr[i+1])
    if(len(arr)>1 and arr[0]==-1):
        brr.append(arr[1])
    if(len(arr)>1 and arr[len(arr)-1]==-1):
        brr.append(arr[len(arr)-2])
    s=set(brr)
    brr=[]
    for i in s:
        if(not i==-1):
            brr.append(i)
    if(len(brr)==0):
        brr.append(42)
    ans=(max(brr)+min(brr))//2 
    crr=[]
    for i in arr:
        if(i==-1):
            crr.append(ans)
        else:
            crr.append(i)
        
    maxx=-1
    for i in range(0,len(arr)-1):
        if(abs(crr[i]-crr[i+1])>maxx):
            maxx=abs(crr[i]-crr[i+1])
    print(maxx,ans)