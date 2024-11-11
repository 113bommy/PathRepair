H,W=map(int,input().split())
S=["."+input()+"." for i in range(H)]
field=["."*(W+2)]+S+["."*(W+2)]

flag=0

for k in range(1,H+1):
    for j in range(1,W+1):
        if field[k][j]=='#' and field[k-1][j]!='#' and field[k+1][j]!='#' and field[k][j-1]!='#' and field[k][j+1]!='#':
            flag=1

if flag==1:
    print('No')
else:     
    print('Yes')