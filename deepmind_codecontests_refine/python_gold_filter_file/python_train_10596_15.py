N, K = map(int, input().split())
s = 0
while N >= K**s:
    s = s+1
print (s)