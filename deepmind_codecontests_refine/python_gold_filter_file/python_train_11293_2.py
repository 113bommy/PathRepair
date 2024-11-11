m,n=map(int,input().split(' '))
lis=[]
for x in range(n):
    str1=input()
    lis.append(str1)

for x in range(2*m):
    for y in range(2*n):
        print(lis[y//2][x//2],end='')
    print('')