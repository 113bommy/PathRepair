H,W  = map(int,input().split())
s = []
ans = 'Yes'
for _ in range(H):
    s.append(input())

for i in range(1,H-1):
    for j in range(1,W-1):
        if s[i][j]=='#' and s[i][j+1]==s[i+1][j]==s[i][j-1]==s[i-1][j]=='.':
                print('No')
                exit()
print(ans)