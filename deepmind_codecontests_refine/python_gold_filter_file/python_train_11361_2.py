t=int(input())
for _ in range(t):
    
    n,m=map(int,input().split())
    l=[]
    for i in range(m):
        l.append(chr(97+i))
    p=n//m
    q=n%m
    print(''.join(map(str,(p*l+l[:q]))))