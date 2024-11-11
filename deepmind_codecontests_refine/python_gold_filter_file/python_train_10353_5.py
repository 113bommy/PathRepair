n, v = map(int, input().split())
s = []
for i in range(n):
    if v > min(map(int, input().split()[1: ])):
        s.append(str(i + 1))
print(len(s))
print(' '.join(s))