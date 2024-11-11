n = int(input())
c = 1
s = 0
packs = 0
while n>s+1:
    packs += 1
    c*=2
    s += c
print(packs+1)
