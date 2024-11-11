[n,a,b]=[int(x)-1 for x in input().split()]
res=0
while a!=b:
    a//=2
    b//=2
    res+=1
if 2**res==n+1:
    res="Final!"
print(res)