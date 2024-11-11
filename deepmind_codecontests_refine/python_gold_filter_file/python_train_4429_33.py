n, c = map(int, input().split())
p = [int(i) for i in input().split()]
t = [int(i) for i in input().split()]
a = 0
s1 = 0
s2 = 0
for i in range(n):
    a += t[i]
    s1 += max(0, p[i] - a * c)
a = 0
for i in reversed(range(n)):
    a += t[i]
    s2 += max(0, p[i] - a * c)
if s1 > s2:
    print('Limak')
elif s1 < s2:
    print('Radewoosh')
else:
    print('Tie')