k = int(input())
lis=[[0]*4 for i in range(3)]
a = 1<<17
#print(a)
lis[0][0]=a+k
lis[0][1]=k
lis[0][2]=k
lis[0][3]=0
lis[1][0]=a
lis[1][1]=1
lis[1][2]=k
lis[1][3]=0
lis[2][0]=a
lis[2][1]=a
lis[2][2]=k+a
lis[2][3]=k
print(3,4)
for i in lis:
    print(*i)
