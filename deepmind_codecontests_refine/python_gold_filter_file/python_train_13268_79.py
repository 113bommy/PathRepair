s = int(input())
c = 0
for i in range(s):
    t = list(map(int, input().split(' ')))
    if t[1] - t[0]>=2:
        c+=1
print(c)