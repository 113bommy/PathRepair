n = int(input())
a = []
for x in range(0, n):
    m = input()
    if len(m) > 10:
        m = (m[0] + str((len(m) - 2)) + m[-1])
    a.append(m)
for i in a:
    print(i, end = '\n')
