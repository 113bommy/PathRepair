_ = int(input())
ts = [int(s) for s in input().split()]

d = {}

for i, t in enumerate(ts):
    d[t] = i

mint = None
for t in d.keys():
    if (mint == None) or (d[t] < d[mint]):
        mint = t

print(mint)
