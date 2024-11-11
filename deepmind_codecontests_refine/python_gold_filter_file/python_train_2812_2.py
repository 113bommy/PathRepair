s = input()
snum = set(map(int, input().split()))
q = input()
qnum = list(map(int, input().split()))
c = 0
for i in qnum:
    if i in snum:
        c += 1

print(c)