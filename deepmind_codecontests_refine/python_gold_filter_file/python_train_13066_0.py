n,k=map(int,input().split())
d=dict()
lo=hi=ans1=ans2=0
lst=list(map(int,input().split()))
for i in range(n):   
    if lst[i] not in d:
        d[lst[i]]=1
    else:
        d[lst[i]]+=1
    hi+=1                       
    if len (d) > k: 
       
        if ans2-ans1 <= (hi-1)-lo:
            ans2=hi-1 ;ans1=lo
        while len(d) == k+1 :
            d[lst[lo]]-=1
            if d[lst[lo]] == 0:
                del d[lst[lo]]
            lo+=1

                   
if ans2-ans1 <= (hi-1)-lo:
    ans2=hi ;ans1=lo
        
print(ans1+1 , ans2)
