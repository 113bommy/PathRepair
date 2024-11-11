N = int(input())
W = list(map(int, input().split()))
dif = [abs(sum(W[:T + 1]) - sum(W[T + 1:])) for T in range(N - 1)]
print(min(dif))