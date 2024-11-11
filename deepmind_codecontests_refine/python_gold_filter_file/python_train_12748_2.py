n = int(input())
c = 0
for i in range(n-1):
    c=(c+i+1)%n
    print(c+1, ' ')