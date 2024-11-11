n,d=list(map(int,input().split()))
sk = list(map(int,input().split()))
pk=list(map(int,input().split()))

sk[d-1] += pk[0]
rank=1

for i in range(d-1):
    if sk[i]+pk[-1]>sk[d-1]:
        rank+=1
    else:
        del pk[-1]
    

print(rank)

    
