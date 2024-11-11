import math
T1, T2 = map(int,input().split())
A1, A2 = map(int,input().split())
B1, B2 = map(int,input().split())

if A1*T1+A2*T2 == B1*T1+B2*T2:
    print('infinity')
elif (A1-B1)*T1/((A1-B1)*T1+(A2-B2)*T2) > 0:
    print(0)    
else:
    n = abs((A1-B1)*T1/((A1-B1)*T1+(A2-B2)*T2))
    meet = math.ceil(n) + int(n)
    print(meet)   