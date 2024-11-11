N=int(input())
a=list(map(int,input().split()))
o=0
m=0
u=[0]*8
for i in a:
    if 3199<i:
        o+=1
    else:
        if u[i//400]==0:
            u[i//400]+=1
            m+=1
print(max(m,1),m+o)