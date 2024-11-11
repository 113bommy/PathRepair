t=int(input())

a=[]
b=[]
for i in range(t):
    a.append([])
    b.append(int(input()))
    a[i]=[int(a[i]) for a[i] in input().split()]
    if(a[i][0]+a[i][1]>a[i][b[i]-1]):
        print('-1')
    else:
        print('1 2',end=' ')
        print(b[i])