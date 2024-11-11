n = int(input())

for i in range(n//7+1):
    if (n-i*7) % 4 == 0:
        print('Yes')
        exit()
print('No')