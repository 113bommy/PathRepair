import sys
input = sys.stdin.readline
alpha="abcdefghijklmnopqrst"
for f in range(int(input())):
    n=int(input())
    a=input()
    a=a[0:n]
    b=input()
    b=b[0:n]
    difs=[False]*20
    for i in range(20):
        difs[i]=[False]*20
    poss=True
    for i in range(n):
        if a[i]!=b[i]:
            if b[i]<a[i]:
                poss=False
            else:
                j1=0
                while a[i]!=alpha[j1]:
                    j1+=1
                j2=j1+1
                while b[i]!=alpha[j2]:
                    j2+=1
                difs[j1][j2]=True
    sol=0
    if poss:
        for j1 in range(19):
            fnd=False
            got=-1
            for j2 in range(j1+1,20):
                if difs[j1][j2]:
                    if fnd:
                        difs[got][j2]=True
                    else:
                        fnd=True
                        got=j2
                        sol+=1
        print(sol)
                    
    else:
        print(-1)