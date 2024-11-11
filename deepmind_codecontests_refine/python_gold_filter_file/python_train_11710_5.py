N = int(input())
span = []

for _ in range(N):
  x,w = list(map(int, input().split()))
  span.append([x-w,x+w])

span = sorted(span, key=lambda x: x[1])
max_clique = 1

for i in range(1, N):
  if span[i-1][1] > span[i][0]:
    span[i][1] = span[i-1][1]
  else:
    max_clique += 1

print(max_clique)