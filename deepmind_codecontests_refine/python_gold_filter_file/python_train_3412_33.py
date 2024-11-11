K = int(input())

n = 0
for i in range(1,K+1):
    n = (n*10 + 7)%K
    if n == 0:
        print(i)
        break

else:
    print(-1)