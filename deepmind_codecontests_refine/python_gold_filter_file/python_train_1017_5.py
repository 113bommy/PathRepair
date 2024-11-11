N, K, S = map(int, input().split())
m = 1
a = [S]*K + [S//2+3]*(N-K)
print(" ".join([str(i) for i in a]))
