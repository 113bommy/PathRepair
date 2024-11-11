r=int(input().split()[0])
m=[list(map(int,input().split()))for _ in[0]*r]
for s in m:s.append(sum(s))or print(*s)
print(*[sum(c)for c in zip(*m)])
