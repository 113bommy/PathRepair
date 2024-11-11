n,p,k=map(int,input().split())
a=(p-k if p>k else 1)
b=(p+k if p+k<=n else n)
s=""
for i in range(a,b+1):
    if i == a and i!=1:
        s+="<< "+str(i)
        continue
    if i==p:
        s+=" ("+str(p)+") "
        continue
    if(i==b and i!=n):
        s+=str(b)+" >>"
        continue
    s+=" "+str(i)+" "

print(s)