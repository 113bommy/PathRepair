for _ in range(int(input())):
    n=int(input())
    c=[input(),input()]
    x=0
    for i in range(n):
        if c[x][i]!='1' and c[x][i]!='2':
            x^=1
            if c[x][i]=='1' or c[x][i]=='2':
                x=0;break
    if x==1:print("YES")
    else:print("NO")