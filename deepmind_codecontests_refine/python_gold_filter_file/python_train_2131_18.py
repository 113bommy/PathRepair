n = int(input())

for i in range(1, 21):
    n1 = n + i
    if '8' in str(n1):
        print(i)
        exit()


