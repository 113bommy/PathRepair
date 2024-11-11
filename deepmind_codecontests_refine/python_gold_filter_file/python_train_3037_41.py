n = int(input())
S = list(map(int, input().split()))
q = int(input())

sums = [0]
s = 0

for i in range(n):
    s += S[i]
    sums.append(s)

for _ in range(q):
    l ,r = map(int, input().split())
    print((sums[r]-sums[l-1])//10)