r,c=[int(s) for s in input().split()]
f=True
a=[]
for i in range(r):
    s=input()
    a.append([])
    for j in range(c):
        a[i].append(s[j])
for i in range(r):
    for j in range(c):
        if a[i][j]=='W':
            if i-1>=0:
                if a[i-1][j]=='.':
                    a[i-1][j]='D'
                if a[i-1][j]=='S':
                    f=False
            if i+1<r:
                if a[i+1][j]=='.':
                    a[i+1][j]='D'
                if a[i+1][j]=='S':
                    f=False
            if j-1>=0:
                if a[i][j-1]=='.':
                    a[i][j-1]='D'
                if a[i][j-1]=='S':
                    f=False
            if j+1<c:
                if a[i][j+1]=='.':
                    a[i][j+1]='D'
                if a[i][j+1]=='S':
                    f=False
if f:
    print('Yes')
    for i in a:
        print(''.join(i))
else:
    print('No')
