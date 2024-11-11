import math

N,L=map(int,input().split())
T=[int(input()) for i in range(N)]

ANSX=ANSY=0

for i in range(N-1):
    for j in range(i+1,N):
        ANSX+=math.cos((T[i]+T[j])*math.pi/L)*(N-(j-i+1))
        ANSY+=math.sin((T[i]+T[j])*math.pi/L)*(N-(j-i+1))

        ANSX+=math.cos((T[i]+T[j])*math.pi/L+math.pi)*(j-i-1)
        ANSY+=math.sin((T[i]+T[j])*math.pi/L+math.pi)*(j-i-1)

print(ANSX/(N*(N-1)*(N-2)//6),ANSY/(N*(N-1)*(N-2)//6))