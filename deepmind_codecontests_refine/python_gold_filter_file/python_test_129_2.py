from collections import defaultdict as dd
for _ in range(int(input())):
    n=int(input())
    d=dd(int)
    
    l=list(map(int,input().split()))
    for i in range(1,n+1):
        d[i]=0
    ans=[]
    for i in l :
        if i<=n and d[i]==0 :
            d[i]=1 
        else:
            ans.append(i)
            
    ans.sort(reverse=True)
    
    cnt=0
    flag=0
    for i in range(1,n+1):
        if d[i]==0 :
            if ans[-1]<=2*i :
                print(-1)
                flag+=1
                break
            else:
                cnt+=1
                ans.pop()

    if flag==0 :
        print(cnt)
            