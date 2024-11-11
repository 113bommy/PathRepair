N = int(input())
D = list(map(int,input().split()))
d = sorted(D)
print(d[N//2]-d[N//2-1])