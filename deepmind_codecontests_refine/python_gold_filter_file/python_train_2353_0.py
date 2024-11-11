from sys import stdin, stdout
MN = 200005

inp = stdin.readline().split()

n = int(inp[0])
k = int(inp[1])
q = int(inp[2])

dod = [0] * MN
pref = [0] * MN

cnt = 0

for i in range(0, n) :
    inp = stdin.readline().split()
    dod[int(inp[0])] += 1
    dod[int(inp[1]) + 1] -= 1

for i in range(1, MN) :
    cnt += dod[i]
    pref[i] = pref[i - 1]
    if(cnt >= k) :
        pref[i] += 1

for i in range(0, q) :
    inp = stdin.readline().split()
    stdout.write(str(pref[int(inp[1])] - pref[int(inp[0]) - 1]) + "\n")
    
