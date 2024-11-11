n = int(input())
s = list(int(i) for i in input())
a = []
maxu = 0
for _ in range(n):
    a.append(list(map(int, input().split())))

for i in range(1000):
    #print(s)
    coun = s.count(1)
    if coun > maxu:
        maxu = coun
    for j in range(n):
        if i - a[j][1] >= 0:
            if ((i-a[j][1])%a[j][0])==0:
                s[j] = 1 - s[j]
print(maxu)
    