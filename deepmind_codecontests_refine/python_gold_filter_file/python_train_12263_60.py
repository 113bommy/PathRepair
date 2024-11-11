
n=int(input())

for i in range(n+1):
    if i*108//100==n:
        print(i)
        exit()
print(":(")
