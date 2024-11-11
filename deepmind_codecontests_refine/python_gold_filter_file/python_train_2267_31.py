X, N = list(map(int, input().split()))
P = list(map(int, input().split()))

l = [i for i in range(102)]
l = list(set(l) - set(P))

print(min(l, key=lambda n: abs(X - n)))