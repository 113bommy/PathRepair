def gcd(a, b) :
    while(b != 0):
        t = a;
        a = b;
        b = t%b;
    return a;
n,m=map(int,input().split())
c=0
ans="Possible "+chr(10)
for i in range(1,n+1):
    for j in range(i+1,n+1):
        if gcd(i,j)==1:
            ans+=str(i)+" "+str(j)+chr(10)
            c+=1
        if c==m:
            break
    if c==m:
        break
if c!=m or n-1>m:
    print("Impossible")
else:
    print(ans)
