N = int(input())
X = sorted(list(map(int,input().split())))
print(X[N//2]-X[N//2-1])