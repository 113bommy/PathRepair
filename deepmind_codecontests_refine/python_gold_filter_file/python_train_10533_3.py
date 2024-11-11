n=int(input())
lst1=list(map(int,input().split()))[:n]
lst2=list(map(int,input().split()))[:n]
dict={}
for a in lst1:
    if a in dict:
        dict[a]+=1

    else:
        dict[a]=1


ans=0
grp=[]

for k in dict:
    if(dict[k]>1):
        grp.append(k)



for i in range(n):
    for k in grp:
        
        if(lst1[i]|k==k):
            ans +=lst2[i]
            break
print(ans)
