N = int(input())
P = sorted(list(map(int, input().split())))

print(P[N//2]-P[N//2-1])