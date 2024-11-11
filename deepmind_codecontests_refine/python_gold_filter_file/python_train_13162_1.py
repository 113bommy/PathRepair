n , v = map(int , input().split())
l = list(map(int,input().split()))
l.sort()
l.pop()

if v >= sum(l):
    print('YES')
else:
    print('NO')

