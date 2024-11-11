n, *A = map(int, open(0).read().split())
B = [0] * 9
for a in A:
  if a < 3200:
  	B[a // 400] = 1
  else:
    B[8] += 1
print(max(sum(B[:8]), 1), sum(B))