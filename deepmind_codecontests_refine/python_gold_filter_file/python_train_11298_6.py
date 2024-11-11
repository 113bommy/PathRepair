n = int(input())
rat = []
wc = []
man = []
cap = []
for i in range(n):
    a,b = input().split()
    if b == 'captain':
        cap.append(a)
    if b == 'rat':
        rat.append(a)
    if b == 'man':
        man.append(a)
    if b == 'woman' or b=="child":
        wc.append(a)
# cap = sorted(cap)
# rat = sorted(rat)
# wc = sorted(wc)
# man = sorted(man)
for i in range(len(rat)):
    print(rat[i])
for i in range(len(wc)):
    print(wc[i])
for i in range(len(man)):
    print(man[i])
for i in range(len(cap)):
    print(cap[i])