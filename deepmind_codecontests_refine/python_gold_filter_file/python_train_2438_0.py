k = int(input())
cards = []
res = []
for i in range(k):
    str = input()
    it = set(map(int,str.split(" ")[1:]))
    cards.append(it)
s = []
for i in cards:
    for j in cards:
        s.append(len(j.difference(i)))
    if s.count(0) != 1:
        print('NO')
    else:
        print('YES')
    s=[]