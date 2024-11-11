n=int(input())
a,b={},{}
r=i=0
for u in input().split():c=a[u]=a.get(u,0)+1;d=b[c]=b.get(c,0)+c;r=(d,r)[d==n or d<i];i+=1
print(r+1)