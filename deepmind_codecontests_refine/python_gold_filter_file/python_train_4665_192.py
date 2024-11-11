N = int(input())
D = sorted(list(map(int, input().split())))
print(D[N//2]-D[(N//2-1)])