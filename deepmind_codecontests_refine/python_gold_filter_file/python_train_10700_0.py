N, K = map(int, input().split())
p = list(map(int, input().split()))
ans = [sum(p[:K])]
for i in range(N-K):
  ans.append(ans[-1]-p[i]+p[i+K])
print(max(ans)/2+K/2)