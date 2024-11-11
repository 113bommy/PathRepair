from math import sin,cos,pi
N,L=map(int,input().split())
S=N*(N-1)*(N-2)/6
T=[int(input())*pi/L for _ in range(N)]
print(sum([sum([cos((T[i]+T[j]))*(N+2*(i-j))for j in range(i+1, N)])for i in range(N)])/S,sum([sum([sin((T[i]+T[j]))*(N+2*(i-j))for j in range(i+1,N)])for i in range(N)])/S)