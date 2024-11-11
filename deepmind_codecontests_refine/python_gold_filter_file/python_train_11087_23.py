#from time import time
n = int(input())
x = list(map(int, input().split()))
#start_time = time()
abc = x[-1]
a = [0]
for i in range(2, n + 1):
    if x[-i] <= abc:
        a.append(abc - x[-i] + 1)
    elif x[-i] > abc:
        abc = x[-i]
        a.append(0)
print(*a[::-1])
#print(time() - start_time)
