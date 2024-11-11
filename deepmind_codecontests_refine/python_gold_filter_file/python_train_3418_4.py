x = [list(map(int,input().split())) for i in range(3)]
m=0
for i in range(3):
    m+=sum(x[i])
if m%3 == 0 and (x[0][0]+x[1][1]+x[2][2])*3==m:
    print('Yes')
else:
    print('No')