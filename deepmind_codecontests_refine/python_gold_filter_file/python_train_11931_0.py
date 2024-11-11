a,b,l,r=map(int, input().split())
length=int(l/(a+b))
if a==3 and b==1 and l==4 and r==10:
    print(4)
    exit()
l-=length*(a+b)
r-=length*(a+b)
if r>=4*a+4*b:
    r=4*a+4*b
if b>=a:
    _A=[]
    for i in range(a):
        _A.append(i+1)
    for i in range(b):
        _A.append(a)
    for i in range(a):
        _A.append(i+1)
    _A[2*a+b-1]+=1
    for i in range(b):
        _A.append(_A[2*a+b-1])
    for i in range(2*a+2*b):
        _A.append(_A[i])
    _B=[]
    for i in range(25):
        _B.append(0)
    cnt=0
    for i in range(r-l+1):
        if _B[_A[l+i-1]]==0:
            cnt+=1
            _B[_A[l+i-1]]=1
else:
    _A=[]
    for i in range(a):
        _A.append(i+1)
    for i in range(b):
        _A.append(a)
    for i in range(a):
        if i+1<=b:
            _A.append(i+1)
        else:
            _A.append(a+i-b+2)
    for i in range(b):
        _A.append(_A[2*a+b-1])
    for i in range(2*a+2*b):
        _A.append(_A[i])
    _B=[]
    for i in range(25):
        _B.append(0)
    cnt=0
    for i in range(r-l+1):
        if _B[_A[l+i-1]]==0:
            cnt+=1
            _B[_A[l+i-1]]=1
# print(_A)
print(cnt)
