l=list(map(int,input().split()))
l1=list(map(int,input().split()))
n=int(input())
r=sum(l)
r1=sum(l1)
if r%5==0 :
    r=r//5
else :
    r=(r//5)+1
if r1%10==0 :
    r1=r1//10
else :
    r1=(r1//10)+1
if r1+r<=n :
    print('YES')
else :
    print('NO')
