n, s = map(int, input().split(" "))

l=[0]*(s+1)

for i in range (n):
    f, t = map(int, input().split(" "))
    if l[f]<t:
        l[f]=t

current=-1

for i in range (s, -1, -1):
    current += 1
    if current < l[i]:
        current = l[i]

print(current)
