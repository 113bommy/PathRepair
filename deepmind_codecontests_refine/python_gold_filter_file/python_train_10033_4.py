import math
n = int(input())
prime = [1]*(n+1)
#for i in range(n):
#prime[i] = 1
prime[0] = 0
prime[1] = 0
for i in range(2, int(math.sqrt(n))+1):
    if prime[i] == 1:
        for j in range(i*2, n+1, i):
            prime[j] = 0
#print(prime)
result = 0

for i in range(6, n+1):
    count = 0
    for j in range(2, int(math.sqrt(i)+1)):
        if i % j == 0:
            if j * j == i:
                if prime[j]:
                    count += 1
            else:
                if prime[j]:
                    count += 1
                if prime[(i//j)]:
                    count += 1
    if count == 2:
        result += 1
print(result)
