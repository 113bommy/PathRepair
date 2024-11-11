n=int(input())
m,c,ci=1001,0,0
for i in input().split():
    i=int(i)
    if n==2 and m!=1001 and m==i:
        n=-1
    if m>i:
        c=ci
        m=i
    ci+=1
if n<=1:
    print(-1)
else:
    print('1\n{0}'.format(c+1))
