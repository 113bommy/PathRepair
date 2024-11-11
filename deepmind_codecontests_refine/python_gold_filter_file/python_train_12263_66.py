n = int(input())
for i in range(50000):
    if int(i*1.08) == n:
        print(i)
        exit()
print(":(")