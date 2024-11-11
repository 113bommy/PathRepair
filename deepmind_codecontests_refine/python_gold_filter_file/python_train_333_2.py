from collections import defaultdict
n,k=map(int,input().split())
arr=list(map(int,input().split()))
rec=defaultdict(list)
for i in arr:
    op=0
    while(i>0):
        rec[i].append(op)
        op+=1
        i=i//2
    #rec[0].append(op)
ans=999999999
for i in rec:
    if(len(rec[i])>=k):
        #print(ans,sum(rec[i][:k]))
        ans=min(ans,sum(sorted(rec[i])[:k]))
print(ans)