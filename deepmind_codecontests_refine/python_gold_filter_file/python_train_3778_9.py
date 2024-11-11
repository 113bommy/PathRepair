from collections import defaultdict
import math
for _ in range(int(input())):
        p,q=map(int,input().split())
        d=defaultdict(int)
        ans=2e18
        for i in range(2,int(math.sqrt(q))+1):
            while q % i == 0:
                q = q//i
                d[i]+=1
            if q == 1: 
                break
        if q > 1: d[int(q)]+=1
        for key,value in d.items():
            temp=p
            c=0
            while temp%int(key)==0:
                temp//=key
                c+=1
            if c<value:
                ans=-1
            else:
                ans=min(ans,math.pow(key,c-value+1))
        if ans==-1:
            print(p)
        else :
            print(max(1,math.floor(p//int(ans))))