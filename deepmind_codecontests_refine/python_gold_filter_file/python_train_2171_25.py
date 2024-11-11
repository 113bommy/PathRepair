a,b,c = map(int,input().split())
cnt = 0

if a == b and a== c and a%2 == 0:
    print(-1)
    exit()

while a%2 == 0 and b%2 == 0 and c%2 == 0:
    cnt+=1
    i=a
    j=b
    a=(b+c)//2
    b=(i+c)//2
    c=(i+j)//2

print(cnt)