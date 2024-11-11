x = int(input())

n = int((2*x)**0.5)

for i in range(n, n+3):
    if i*(i+1) >= x*2:
        print(i)
        exit()