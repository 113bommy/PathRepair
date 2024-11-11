n,k = map(int, input().split())
s = []
for i in range(k):
  d = int(input())
  a = list(map(int, input().split()))
  s += a
print(n-len(set(s)))
  