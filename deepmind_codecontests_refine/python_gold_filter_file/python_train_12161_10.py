n, m, c = map(int, input().split())
bl = [int(i) for i in input().split()]
ans = 0
for i in range(n):
  al = [int(j) for j in input().split()]
  ans += sum([bl[j] * al[j] for j in range(m)]) + c > 0
print(ans)