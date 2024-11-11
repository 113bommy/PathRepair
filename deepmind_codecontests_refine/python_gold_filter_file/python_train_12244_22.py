#n = int(input())
n, m = map(int, input().split())
s = input()
#c = list(map(int, input().split()))
a = []
b = []
for i in range(n):
    if s[i] in b:
        a[b.index(s[i])] += 1
    else:
        b.append(s[i])
        a.append(1)

if max(a) > m:
    print('NO')
else:
    print('YES')