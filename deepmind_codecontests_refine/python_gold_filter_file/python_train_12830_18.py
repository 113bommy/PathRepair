ans=[]
t=int(input())
for i in range(t):
    n=int(input())
    a=list(map(int,input().strip().split()))[:n]
    a.sort()
    j=n
    while(True):
        if(j==0):
            ans.append(1)
            break
        if(a[j-1]<=j):
            ans.append(j+1)
            break
        else:
            j-=1
for i in ans:
    print(i)