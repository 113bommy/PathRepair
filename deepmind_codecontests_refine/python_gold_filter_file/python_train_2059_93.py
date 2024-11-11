a,v=map(int,input().split())
b,w=map(int,input().split())
t=int(input())

if v*t-abs(b-a)>=w*t:
    print('YES')
else:
    print('NO')