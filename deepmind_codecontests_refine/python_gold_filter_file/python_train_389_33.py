n = int(input())
a = list(map(int,input().split()))
M = max(a)+1
if M == 2:
    print("pairwise coprime")
    exit()
count = [0]*(M)

for i in range(2,M):
    if count[i] == 0:
        for j in range(i,M,i):
            if count[j] == 0:
                count[j] = i
check = [0]*(M)
for i in a:
    x = i
    while x > 1:
        check[count[x]] += 1
        y = count[x]
        while x%y == 0:
            x //= y
ans = max(check)
if ans == 1:
    print("pairwise coprime")
elif ans == n:
    print("not coprime")
else:
    print("setwise coprime")