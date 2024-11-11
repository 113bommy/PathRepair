a,b=list(map(int,input().split()))
k=int(max(str(a)+str(b)))+1
carry=0
l=max(len(str(a)),len(str(b)))
for itr in range(l):
    if a%10+b%10+carry<k: carry=0
    else: carry=1
    a//=10
    b//=10
    #print(a,b)
if carry: print(l+1)
else: print(l)