s1=sum(map(int,input().split()))
s2=sum(map(int,input().split()))
n=int(input())
k=0
if s1%5==0:
    k+=s1//5
else:
    k+=s1//5+1
if s2%10==0:
    k+=s2//10
else:
    k+=s2//10+1
if k<=n:
    print('YES')
else:
    print('NO')
