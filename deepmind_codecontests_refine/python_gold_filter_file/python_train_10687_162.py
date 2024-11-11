giveninput = input().split()
n = int(giveninput[0])
k = int(giveninput[1])
for i in range(k):
    if str(n)[-1] == '0':
        n = int(str(n)[:-1])
    else:
        n -= 1
print(n)