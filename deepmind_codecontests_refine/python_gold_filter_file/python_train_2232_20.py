a=list(map(int,input().split()))
s=input()
d={}
for i in s:
    if(i in d):
        d[i]+=1
    else:
        d[i]=1
#print(d)
c=0
j=0
for i in d:
    c+=d[i]*a[int(i)-1]
    j+=1
print(c)
