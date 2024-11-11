n = int(input())
d = []
d = [int(item) for item in input().split()]
s, t = map(int, input().split())
ss = min(s, t)-1
tt = max(s, t)-1
dist1 = sum(d[ss:tt])

print(min(sum(d)-dist1, dist1))
