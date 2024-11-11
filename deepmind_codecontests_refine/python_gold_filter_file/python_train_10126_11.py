t = int(input())
ansl = []
for _ in range(t):
    n = int(input())
    c_cnts = [0]*26
    for _i in range(n):
        s = input()
        for si in s:
            num = ord(si)-ord('a')
            c_cnts[num] += 1
    if all([c%n==0 for c in c_cnts]):
        ansl.append('YES')
    else:
        ansl.append('NO')

for a in ansl: print(a)