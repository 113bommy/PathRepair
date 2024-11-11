n = int(input())
cnt = 2
memo = {}
prod = 1
while cnt * cnt <= n :
    if n % cnt == 0 :
        prod *= cnt
        while n % cnt == 0 :
            n /= cnt
    cnt += 1

if n > 1 :
    prod *= n
print(int(prod))