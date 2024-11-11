h,w=map(int,input().split())
s=[]
s.append(['.']*(w+2))
for _ in range(h):
    s.append(['.']+list(input())+['.'])
s.append(['.']*(w+2))

flag=True
for i in range(1,h+1):
    for j in range(1,w+1):
        if s[i][j]=='#' and s[i-1][j]=='.' and s[i][j-1]=='.' and s[i+1][j]=='.' and s[i][j+1]=='.':
            flag=False
print('Yes' if flag else 'No')
