n=int(input())
S=input()
S1={}
k=0
for x in S :
    if x.islower() :
        S1[x]=S1.get(x,0)+1
    else :
        v=x.lower()
        if S1.get(v,0)>0 :
            S1[v]-=1
        else :
            k=k+1

print(k)

        
        
