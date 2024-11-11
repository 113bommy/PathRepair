t=int(input())
for i in range(0,t):
    m=int(input())
    arr1=list(map(int,input().strip().split()))[:m]
    l1=[]
    ct=0
    for i in range(0,m-2):
        if(arr1[i]+arr1[i+1]<=arr1[-1]):
            l1.append(i+1)
            l1.append(i+2)
            l1.append(m)
            print(*l1,sep=" ")
            ct+=1
            break
    if(ct==0):
        print("-1")
        