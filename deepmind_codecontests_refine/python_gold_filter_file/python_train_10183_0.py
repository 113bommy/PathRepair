n,k=map(int,input().split())
sushi=[]
for i in range(n):
    sushi.append([])
for i in range(n):
    t,d=map(int,input().split())
    sushi[t-1].append(d)
Max=[]
Rest=[]
v=0
for i in sushi:
    if not i==[]:
        Max.append(max(i))
        i.remove(max(i))
        for j in i:
            Rest.append(j)
        v=v+1
Max.sort(reverse=True)
Rest.sort(reverse=True)
Max_s=[]
Rest_s=[0]
Sum=0
for i in Max:
    Sum=Sum+i
    Max_s.append(Sum)
Sum=0
l_r=0
for i in Rest:
    Sum=Sum+i
    Rest_s.append(Sum)
    l_r=l_r+1
ans=0
for i in range(1,min(k,v)+1):
    if k-i<=l_r:
        temp=Max_s[i-1]+Rest_s[k-i]+i**2
        if ans<temp:
            ans=temp
print(ans)
