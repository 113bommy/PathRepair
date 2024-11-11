
s, v1, v2, t1, t2 = map(int,input().split())
r1 = 2*t1 + v1*s
r2 = 2*t2 + v2*s
if r1<r2:
    print('First')
elif r1>r2:
    print("Second")
else:
    print("Friendship")