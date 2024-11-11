c,r,k=list(map(int,input().split()))

clst=list(map(int,input().split()))
rlst=list(map(int,input().split()))

def check(lst,k):
    if len(lst)<k:
        return 0
    
    ret=0

    cursum=sum(lst[:k])

    if cursum==k:
        ret+=1
    
    for i in range(1,len(lst)-k+1):
        cursum-=lst[i-1]
        cursum+=lst[i+k-1]

        if cursum==k:
            ret+=1
    
    return ret

ans=0

for i in range(1,c+1):
    if k%i==0:
        ccnt=check(clst,i)
        rcnt=check(rlst,k//i)

        ans+=ccnt*rcnt

print(ans)