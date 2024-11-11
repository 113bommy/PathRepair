N, K = map(int,input().split())
AB = sorted([list(map(int,input().split())) for _ in range(N)])

tmp = 0
for a, b in AB:
  if(tmp < K-b):
    tmp += b
  else:
    print(a)
    break