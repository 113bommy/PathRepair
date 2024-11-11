n,m=map(int,input().split())
k=n//m
p=n%m
for i in range(m-p):
    print(k,'',end='')
for i in range(p):
    print(k+1,'',end='')
    
    