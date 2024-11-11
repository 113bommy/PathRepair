n=int(input());l=list(map(int,input().split()))
d={}
for i in range(len(l)):
    if d.get(l[i],-1)==-1:
        d[l[i]]=[0,i]
    else:
        if d[l[i]][0]==0:
            d[l[i]] = [i-d[l[i]][1],i] 
        elif i-d[l[i]][1]== d[l[i]][0]:
            d[l[i]] = [d[l[i]][0],i]
        else:
            d[l[i]]=[-n,-n]
k=0
for i in d.keys():
    if d[i][0]>=0:
        k+=1
print(k)
for i in sorted(d.keys()):
    if d[i][0]>=0:
        print(i,d[i][0])