a = list(map(int,input().split()))
a.extend(list(map(int,input().split())))
a.extend(list(map(int,input().split())))
n = int(input())

ins = []
for i in range(n):
    b = int(input())
    if b in a:
        ins.append(a.index(b))

okp = [(0,1,2), (3,4,5), (6,7,8) ,(0,3,6), (1,4,7), (2,5 ,8), (0,4,8), (2,4,6)]
f = "No"
for x, y, z in okp:
    if x in ins and y in ins and z in ins:
        f = "Yes"
        break

print(f)



    