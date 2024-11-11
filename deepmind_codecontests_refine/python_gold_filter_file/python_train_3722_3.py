n=int(input())
for i in range(514):
    if int(bin(i)[2:])>n:
        print(i-1)
        break
