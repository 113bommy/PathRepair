t=int(input())
for _ in range(t):
    n=int(input())
    l=list(map(int,input().split()))
    arr=[]
    diff=[]
    for i in range(n):
        if(i==0):
            if(l[i]>=0 and l[i+1]==-1):
                arr.append(l[i])
        elif(i==n-1):
            if(l[i]>=0 and l[i-1]==-1):
                arr.append(l[i])
        else:
            if(l[i]>=0 and (l[i-1]==-1 or l[i+1]==-1)):
                arr.append(l[i])
        if(i<n-1):
            if(l[i]>=0 and l[i+1]>=0):
                diff.append(abs(l[i]-l[i+1]))
    arr.sort()
    if(arr==[]):
        print(0,0)
    else:
        if(diff==[]):
            diff.append(0)
        if((arr[-1]-arr[0])%2==0):
            q=(arr[-1]-arr[0])//2
        else:
            q=((arr[-1]-arr[0])//2)+1
        s=max(diff)
        print(max(s,q),(arr[-1]+arr[0])//2)


        
