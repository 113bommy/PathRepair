T1,T2 = map(int,input().split())
A1,A2 = map(int,input().split())
B1,B2 = map(int,input().split())
A1 -= B1
A2 -= B2
if A1 < 0:
    A1 *= -1
    A2 *= -1

if A1*T1 > -A2*T2:
    print(0)
elif A1*T1 == -A2*T2:
    print("infinity")
else:
    dx = -A2*T2 -A1*T1
    ans = (A1*T1)//dx *2 +1
    if (A1*T1)%dx == 0:
        ans -= 1
    print(ans)