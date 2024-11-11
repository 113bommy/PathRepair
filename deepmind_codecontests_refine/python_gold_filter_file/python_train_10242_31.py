a = input().split()
b = input().split()
c = input().split()
lis = [a, b, c]
for i in range(3):
    for j in range(3):
        lis[i][j]=int(lis[i][j])
newl=[[0,0,0],[0,0,0],[0,0,0]]
for i in range(3):
    newl[0][i]=lis[0][i]+lis[1][i]
    newl[2][i]=lis[2][i]+lis[1][i]
    newl[1][i]=lis[0][i]+lis[1][i]+lis[2][i]
for i in range(3):
    newl[i][0]=(newl[i][0]+lis[i][1]+1)%2
    newl[i][2]=(newl[i][2]+lis[i][1]+1)%2
    newl[i][1]=(newl[i][1]+lis[i][0]+lis[i][2]+1)%2
print(str(newl[0][0])+str(newl[0][1])+str(newl[0][2]))
print(str(newl[1][0])+str(newl[1][1])+str(newl[1][2]))
print(str(newl[2][0])+str(newl[2][1])+str(newl[2][2]))