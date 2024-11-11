n=int(input())
for i in range(50001):
    if i*108//100==n:
        print(i)
        exit()
print(':(')