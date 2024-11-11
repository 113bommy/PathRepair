n, m = map(int, input().split())
seq = [i for i in range(1, n+1)]
m -= 1
dig = []
digs = 0
while m > 0:
    dig.append(m % 2)
    m //= 2
    digs += 1
swap = 0
sw = [0] * digs
for i in range(digs - 1, -1, -1):
    if swap == 1:
        sw[i] = 1 - dig[i]
    else:
        sw[i] = dig[i]
    swap = (swap + sw[i]) % 2
for i in range(digs):
    if sw[i] == 1:
        seq[-i-2:] = seq[:-i-3:-1]
print(" ".join(map(str, seq)))