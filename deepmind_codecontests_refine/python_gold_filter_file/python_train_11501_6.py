m,s=map(int,input().split())
if (m>1 and s==0) or 9*m<s:
    print(-1,-1)
elif s<=9:
    if m>=2:
        print('1'+'0'*(m-2)+str(s-1),str(s)+'0'*(m-1))
    else:
        print(s,s)
else:
    k=s//9
    if k==m:
        print('9'*k,'9'*k)
    else:
        l=s%9
        n=m-k
        if n==1:
            print(str(l)+'9'*k,'9'*k+str(l))
        elif n!=1 and l==0:
            print('1'+'0'*(n-1)+'8'+'9'*(k-1),'9'*k+'0'*n)
        else:
            x=l-1
            print('1'+'0'*(n-2)+str(x)+'9'*k,'9'*k+str(l)+'0'*(n-1))