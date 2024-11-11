from sys import stdin as fin
# fin = open("cfr343b.in", "r")

n = int(fin.readline())
# days = [] * n
events = []

for i in range(n):
    inp = fin.readline().split()
    g = inp[0]
    s, t = map(int, inp[1:])
    events.append((s - 1, True, g), )
    events.append((t, False, g))

events.sort()

days = [[0] * 2 for i in range(367)]
# m_bal = f_bal = 0
for (i, type, g) in events:
    # print(i, type, g, days[i][0], days[i][1], end = " => ")
    if type:
        if g == 'M':
            days[i][0] += 1
        else:
            days[i][1] += 1

    else:
        if g == 'M':
            days[i][0] -= 1
        else:
            days[i][1] -= 1
    # print(i, type, g, days[i][0], days[i][1])
# print(days)

m_bal = f_bal = 0
maxv = 0
for (mc, fc) in days:
    (m_bal, f_bal) = (m_bal + mc, f_bal + fc)
    # print((m_bal, f_bal), end=' ')
    # maxv = max(maxv, min(f_bal, m_bal) * 2)
    if min(f_bal, m_bal) * 2 > maxv:
        # print(min(f_bal, m_bal) * 2, m_bal, f_bal)
        maxv = min(f_bal, m_bal) * 2

# print(max(days))
print(maxv)