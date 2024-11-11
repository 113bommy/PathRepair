import sys
input = sys.stdin.readline
for _ in range(int(input())):
    n=int(input())
    arr=[int(x) for x in input().split()]
    temp=[0 for i in range(n)]
    ans=0
    for i in range(n):
        curr=temp[i]
        if temp[i]+1<arr[i]:
            ans+=(arr[i]-(curr+1))
            curr+=arr[i]-(curr+1)
        if i!=n-1:
            temp[i+1]+=curr-arr[i]+1
            
            #arr[i]=1
        for j in range(i+2,min(n,arr[i]+i+1)):
            temp[j]+=1
        #print(temp)
            

        
    print(ans)