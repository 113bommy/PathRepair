a,b,c=map(int,input().split())
if a==b==c:
    if a%2==b%2==c%2==0:
        print(-1)
    else:
        print(0)
    exit()
cnt=0
while a%2==b%2==c%2:
    A=a//2
    B=b//2
    C=c//2
    a,b,c=B+C,A+C,A+B
    cnt+=1
print(cnt)