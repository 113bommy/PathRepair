n, k, m = [int(i) for i in input().split()]
t = sorted([int(i) for i in input().split()])
st = sum(t)

best = -1

# try all values for solved tasks
for s in range(min(n, m//st)+1):
  score = s*(k+1)
  rm = m - s*st
  for j in range(k):
    q = min(n-s, rm//t[j])
    rm -= q*t[j]
    score += q
  best = max(best, score)
  
print(best)