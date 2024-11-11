from collections import defaultdict as d

t=int(input())
for _ in range(t):
    n=int(input())
    s=input()
    arr=[int(x) for x in s]
    
    p=[0] #prefix sums
    for x in arr:
        p.append(p[-1]+x)

            
    cnts=d(lambda :0)
    for i in range(n+1):
        diff=p[i]-i
        cnts[diff]+=1
    
#    print(p)
#    print(cnts)
    
    total=0
    for v in cnts.values(): #choose 2 indexes for each set of indexes that give same p[i]-i
        if v>=2:
            total+=v*(v-1)//2
    print(total)