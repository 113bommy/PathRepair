N = int(input())
for i in range(N//7+1):
    if (N-i*7) % 4 == 0:
        print('Yes')
        exit()
print('No')