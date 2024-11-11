n=int(input())
d={}
l=[]
for i in range(n-1):
    a,b=map(int,input().split())
    l.append([a,b])
    if (a in d):
        d[a]+=1
    else:
        d[a]=1
    if (b in d):
        d[b]+=1
    else:
        d[b]=1
ans=[-1]*(n-1)
pew=0
for i in range(1,n+1):
    if (d[i]>=3):
        for j in range(n-1):
            if (l[j][0]==i or l[j][1]==i):
                ans[j]=pew
                pew+=1
                if (pew==3):
                    break
                
        for j in range(n-1):
            if (ans[j]==-1):
                ans[j]=pew
                pew+=1
        break
    
for j in range(n-1):
            if (ans[j]==-1):
                ans[j]=pew
                pew+=1
for i in ans:
    print(i)
                
                
                
        
    