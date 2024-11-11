inp = [int(x) for x in input().split(' ')]

n = inp[0]
m = inp[1]

var1 = [x for x in input().split(' ')]

var2 = [x for x in input().split(' ')]

q = int(input())


lines = []
for i in range(q):
    line = int(input())
    if line:
        lines.append(line)
    else:
        break


for i in lines:
    stri = ''
    stri += var1[(i-1) % n]
    stri += var2[(i-1) % m]
    print(stri)
