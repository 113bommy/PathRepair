i = int(input())
l = list(sorted(list(map(int,input().split())),reverse=True))

c= i
t = 0
for x in l:
    t += abs(c-x)
    c -= 2

p= i-1
g = 0
for y in l:
    g += abs(p-y)
    p -= 2

print(min(t,g))