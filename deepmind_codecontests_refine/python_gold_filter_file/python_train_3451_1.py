x = int(input())
n = len(str(bin(x))) - 2
curr = (1 << n) - 1
res = 0
resList = []
for i in range(0, n) :
        if (x ^ curr < x) :
                x = x ^ curr
                res = res + 2
                resList.append(n - i)
        curr = curr >> 1

print(res - 1)
print(*resList)