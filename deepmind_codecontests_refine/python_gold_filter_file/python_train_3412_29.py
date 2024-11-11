k = int(input())
a = 7
for i in range(1, k + 1):
    if a % k == 0:
        print(i)
        exit()
    a = (10 * a + 7) % k
print(-1)
