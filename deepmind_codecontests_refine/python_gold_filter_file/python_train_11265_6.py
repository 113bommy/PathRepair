n = int(input())
l = list(map(int, input().split(' ')))
lefts = []
leftsc = []
rights = []
rightsc = []
b = 0
for i in range(0, n - 1):
    if b == 0:
        if l[i] < l[i + 1]:
            b = 1
            lefts.append(l[i])
            leftsc.append(i)
        else:
            lefts.append(l[i])
            leftsc.append(i)
            rights.append(l[i])
            rightsc.append(i)
    if l[i] >= l[i + 1] and b == 1:
        b = 0
        rights.append(l[i])
        rightsc.append(i)
if l[n-2] < l[n - 1]:
    rights.append(l[n - 1])
    rightsc.append(n - 1)
else:
    lefts.append(l[n-1])
    leftsc.append(n-1)
    rights.append(l[n - 1])
    rightsc.append(n - 1)
maxl = 0

for i in range(len(lefts)):
    maxl = max(maxl, rightsc[i] - leftsc[i] + 1)

if len(lefts) == 1:
    print(rightsc[0] - leftsc[0] + 1)
    exit(0)
for i in range(len(lefts) - 1):
    if rights[i] >= lefts[i + 1]:
        if rightsc[i] - 1 >= 0:
            if l[rightsc[i] - 1] < lefts[i + 1]:
                if maxl < rightsc[i + 1] - leftsc[i]:
                    maxl = rightsc[i + 1] - leftsc[i]
        if rightsc[i] + 1 < n:
            if leftsc[i + 1] + 1 < n:
                if l[rightsc[i]] < l[leftsc[i + 1] + 1]:
                    if maxl < rightsc[i + 1] - leftsc[i]:
                        maxl = rightsc[i + 1] - leftsc[i]
print(maxl)