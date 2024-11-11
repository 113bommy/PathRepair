import math
def phi(n):
    res = n
    for i in range(2, int(math.sqrt(n)) + 1):
        if(n % i == 0):
            while(n % i == 0):
                n /= i
            res -= res/i
    if(n > 1):
        res -= int(res / n)
    return res
n, k = map(int, input().split())
res = n
k = int((k + 1) / 2)
while(res != 1 and k != 0):
    res = phi(res)
    k -= 1
print("{}".format(int(res % (1e9 + 7))))