n,t=map(int,input().split())
if n==1 and t==10:
    print(-1)
elif n!=1 and t==10:
    print(int('1'*(n-1)+'0'))
else:
    print(int(''.join([str(1*t)]*n)))