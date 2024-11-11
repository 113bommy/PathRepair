N, K = map(int, input().split())
ab_list = sorted([list(map(int, input().split())) for _ in range(N)])

for a, b in ab_list:
  if b >= K:
    print(a)
    exit()
  else:
    K -= b
