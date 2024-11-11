t=int(input())
for _ in range(t):
    n,a,b=map(int,input().split())
    s=97
    rep,ct=a-b,0
    while(ct!=n):
        c=s
        for i in range(b):
            if ct>=n: break
            print(chr(c),end='')
            ct+=1
            c+=1
        for i in range(rep):
            if ct>=n: break
            print(chr(min(c-1,122)),end='')
            ct+=1
    print('')
