a,b,c,d = map(int,input().split())
h,m = 50,50
a1 = ['A'*25 for i in range(25)]
b1 = ['B'*25 for i in range(25)]
c1 = ['C'*25 for i in range(25)]
d1 = ['D'*25 for i in range(25)]
a -= 1
b -= 1
c -= 1
d -= 1
print(50,50)
for i in range(1,25-1,2):
    for j in range(1,25-1,2):
        if(b != 0):
            b -= 1
            a1[i] = a1[i][:j] + 'B' + a1[i][j+1:]


for i in range(1,25-1,2):
    for j in range(1,25-1,2):
        if(a != 0):
            a -= 1
            b1[i] = b1[i][:j] + 'A' + b1[i][j+1:]


for i in range(1,25-1,2):
    for j in range(1,25-1,2):
        if(c != 0):
            c -= 1
            d1[i] = d1[i][:j] + 'C' + d1[i][j+1:]


for i in range(1,25-1,2):
    for j in range(1,25-1,2):
        if(d != 0):
            d -= 1
            c1[i] = c1[i][:j] + 'D' + c1[i][j+1:]

for i in range(25):
    print(a1[i] + b1[i])
for i in range(25):
    print(c1[i] + d1[i])