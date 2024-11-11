n = int(input())

for i in range(n):
    t = list(map(int,input().split()))
    print((t[1]-t[0]%t[1])%t[1])
