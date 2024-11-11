n = int(input())
top = int(((8*n-7)**.5-1)/2) + 1
flag = False
for m1 in range(1, top):
    m2 = int(((8*n + 2 - (2*m1+1) ** 2) ** .5 - 1)/2)
    if (2*m1 + 1) ** 2 + (2*m2 + 1) ** 2 == 8*n + 2:
        flag = True
        break
if flag:
    print("YES")
else:
    print("NO")

