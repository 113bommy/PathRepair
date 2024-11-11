n, k = map(int, input().split())
a = list(map(int, input().split()))

dic = {}
for i in range(n):
    if a[i] in dic:
        dic[a[i]].append(i)
    else:
        dic[a[i]] = [i]

zero = [-1 for i in range(n)]
for key, value in dic.items():
    num = len(value)
    for i in range(num-1):
        zero[value[i]] = value[i+1] - value[i] + 1
    zero[value[-1]] = n - value[-1] + value[0] + 1

lst = [zero]
while lst[-1][0] <+ n*k - 1:
    before = lst[-1]
    after = []
    for i in range(n):
        after.append(before[i] + before[(before[i]+i)%n])
    lst.append(after)
lst.pop()

i = 0
while lst != []:
    lsti = lst.pop()
    while True:
        if i + lsti[i%n] <= n*k - 1:
            i = i + lsti[i%n]
        else:
            break

i = i % n
nokori = a[i:]
lst = []
dic = {}
ko = 0
for i in range(len(nokori)):
    if nokori[i] not in dic:
        lst.append(nokori[i])
        dic[nokori[i]] = ko
        ko += 1
    else:
        lst = lst[:dic[nokori[i]]]
        dic = {}
        for j in range(len(lst)):
            dic[lst[j]] = j
        ko = len(lst)
print(*lst)