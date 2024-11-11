n = int(input())
dic = {"JPY": 1, "BTC": 380000}
ans = 0
for i in range(n):
  x,u = input().split()
  ans += float(x) * dic[u]
print(ans)  