n,m=map(int,input().split())
op=[]
if m<=2*n:
    for i in range(1,m+1):
        print(i,end=' ')
else:
    p=m-2*n
    l=p%2
    p=p//2
    for i in range(1,p+1):
        op.append(2*n+2*i-1)
        op.append(2*i-1)
        op.append(2*n+2*i)
        op.append(2*i)
    if l==1:
        op.append(m)
    for i in range(2*p+l,2*n+1):
        op.append(i)
    op2=[]
    for i in op:
        if i not in op2:
            print(i,end=' ')
            op2.append(i)
        
