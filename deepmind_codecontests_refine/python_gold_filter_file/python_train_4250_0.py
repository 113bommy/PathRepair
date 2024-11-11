A, B, K = map(int, input().split())
res = [i for i in range(1, 200) if A % i == 0 and B % i == 0]
print(res[-K])
