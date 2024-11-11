n,m = map(int, input().split())
ma=[]
for i in range(n):
    temp=list(input())
    ma.append(temp)

#print(m)
xl = set()
yl=set()
xy=[]
for i in range(n):
    for j in range(m):
        if ma[i][j] == '*': 
            xl.add(i)
            yl.add(j)
            xy.append([i,j])
for i in xl:
    for j in yl:
        if [i,j] not in xy:
            print(i+1,j+1)
