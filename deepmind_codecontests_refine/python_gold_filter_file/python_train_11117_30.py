N, M = map(int, input().split())
ac = [0] * N
wa = [0] * N
for i in range(M):
    p, S = input().split()
    p = int(p) - 1
    if S == 'AC':
        ac[p] = 1
    if S == 'WA' and ac[p] == 0:
        wa[p] += 1
print(sum(ac), sum(ac[i] * wa[i] for i in range(N)))
