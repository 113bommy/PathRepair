n = int(input())
a = list(map(int, input().split()))
s, x = set(), 0
for i in a:
    if(i < 3200):
        s.add(i//400)
    else:
        x += 1
print(max(len(s), 1), len(s)+x)
