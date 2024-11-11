n=int(input())
arr=list(map(int,input().split()))
d=dict()
count=0 
for i in arr:
    d[i]=d.get(i,0)+1 
for k,v in d.items():
    if not d[k]==k:
        if d[k]<k:
            count+=d[k]
        else:
            count+=d[k]-k 
print(count)