nk = input()
n, k = [int(i) for i in nk.split(" ")]
a = input()
a = [int(i) for i in a.split(" ")]
b = []
for i in range(len(a)):
    b += [(i, a[i])]
b.sort(key = lambda x:x[1])
m = 0
no = 0
p = []
for i in range(n):
    m += b[i][1]
    if m <= k:
        no += 1
        p.append(b[i][0])
    else:
        break
if len(p)>0:
    print(no)
    for i in p:
        print (i+1, end=" ")
else:
    print(0)
