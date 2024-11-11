st = input()
n = int(st.split()[0])
m = int(st.split()[1])

a = [0] * n
Ox = [0] * (m + 1)

for i in range(n):
    a[i] = [0] * 2
    st = input()
    a[i][0] = int(st.split()[0])
    a[i][1] = int(st.split()[1])

for i in range(n):
    l = a[i][0]
    r = a[i][1]
    if r == l:
        Ox[r] = 1
    else:
        for x in range(l, r + 1):
            Ox[x] = 1

answer = []
count = 0
for i in range(1, m + 1):
    if Ox[i] == 0:
        count = count + 1
        answer.append(i)

print(count)
for i in range(count):
    print(answer[i], end=' ')
