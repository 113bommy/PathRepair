n=int(input())
a=list(map(int,input().split()))
s=sum(a)
if s:
    print('YES')
    print(1)
    print(1,n)
    exit()
for i in range(n):
    s-=a[i]
    if s:
        print('YES')
        print(2)
        print(1,i+1)
        print(i+2,n)
        break
else: print('NO')