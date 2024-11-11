n = int(input())
b = list(map(int,input()))
if b.count(0)!=b.count(1):
    print(1)
    print(*b,sep='')
else:
    print(2)
    print(b[0],end = ' ')
    print(*b[1:],sep = '')
