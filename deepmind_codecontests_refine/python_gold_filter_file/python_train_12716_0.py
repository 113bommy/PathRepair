a, b, c = map(int, input().split())
su = 0
if (abs(a-b) <= 1):
    print(a+b+2*c)
else:
    print(2*min(a,b)+2*c+1)