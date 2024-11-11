# 472 C

a = int(input())
l = []
l1 = []
for i in range(a):
    l.append('')
for i in range(a):
    lol = input().split()
    l1.append([lol[0],lol[1]])
l2 = input().split()

for i in range(a):
    l[i] = l1[int(l2[i])-1]
m = ''
work = "YES"
for i in range(a):
    if min(l[i]) >= m:
        m = min(l[i])
    elif max(l[i]) >= m:
        m = max(l[i])
    else:
        work = "NO"
        break

print(work)
