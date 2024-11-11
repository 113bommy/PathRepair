t=int(input())
for _ in range(t):
    n,k=map(int,input().split())
    s=list(input())
    a=['*']*k
    f=0
    for i in range(n):
        if s[i]!='?':
            if s[i]==a[i%k] or a[i%k]=='*':
                a[i%k]=s[i]
            else:
                f=1
                print('NO')
                break
    if f==0:
        star,zero,one=a.count('*'),a.count('0'),a.count('1')
        if abs(zero-one)<=star:
            print('YES')
        else:
            print('NO')