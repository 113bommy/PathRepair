x=int(input())
l=list(map(int,input().split()))
y=list(map(int,input().split()))
if sum(y)<=sum(l):
    print('YES')
else:
    print('NO')
