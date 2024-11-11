n, m, d = map(int, input().split())
p = 1/n if d==0 else 2*(n-d)/n/n
ans = (m-1)*p
print(ans)
