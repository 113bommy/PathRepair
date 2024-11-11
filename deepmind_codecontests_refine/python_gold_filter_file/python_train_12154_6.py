__author__ = 'Esfandiar'
n,m = map(int,input().split())
s=[input() for j in range(n)]
def check(i,j,n,m,s):
    bom = 0
    if i!=0 and j!=0:bom+=s[i-1][j-1]=='*'
    if i!=0:bom+=s[i-1][j]=='*'
    if i!=0 and j+1!=m:bom+=s[i-1][j+1]=='*'
    if j!=0:bom+=s[i][j-1]=='*'
    if j+1!=m:bom+=s[i][j+1]=='*'
    if i+1!=n and j!=0:bom+=s[i+1][j-1]=='*'
    if i+1!=n:bom+=s[i+1][j]=='*'
    if i+1!=n and j+1!=m:bom+=s[i+1][j+1]=='*'
    return bom
for i in range(n):
    for j in range(m):
        if s[i][j]=='*':
            continue
        if s[i][j] == '.':
            if check(i,j,n,m,s) > 0:
                print('NO')
                exit()
        else:
            if check(i,j,n,m,s) != int(s[i][j]):
                print("NO")
                exit()
print("YES")