X, Y, Z, K = map(int, input().split())
A = list(map(int, input().split()))
B = list(map(int, input().split()))
C = sorted(map(int, input().split()), reverse=True)

AB = []
for a in A:
  for b in B:
    AB.append(a+b)
AB.sort(reverse = True)

ans = []
for ab in AB[:K]:
  for c in C:
    ans.append(ab+c)

ans.sort(reverse=True)
print(*ans[:K], sep="\n")