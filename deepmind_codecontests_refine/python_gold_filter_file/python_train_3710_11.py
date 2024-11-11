
h1, a1, c = map(int, input().split())
h2, a2 = map(int, input().split())
7, 5
av = -(h2 // -a1) 
ak = -(h1 // -a2) 
heal = 0
while ak < av:
    h1 += c - a2
    heal += 1
    ak = -(h1 // -a2)
print(av + heal)
for i in range(av + heal):
    if heal != 0:
        print('HEAL')
        heal -= 1
    else:
        print('STRIKE')
    