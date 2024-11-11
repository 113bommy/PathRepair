t = int(input())
for i in range(t):
    a = input()
    b = input()
    answ = 0
    pos = a.find(b[0])
    for j in b[1:]:
        answ += abs(a.find(j) - pos)
        pos = a.find(j)
    print(answ)