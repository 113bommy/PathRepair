n,m=map(int,input().split())
l=[]
for i in range(n):l.append("".join(list(map(str,input().split()))))
if n&1:print(n)
else:
    while 1:
        if l[:n//2]!=l[n//2:n][::-1]:print(n);break
        n//=2