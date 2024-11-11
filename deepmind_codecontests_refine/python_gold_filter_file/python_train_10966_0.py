n,k = map(int,input().split())
for i in range(51):
    if i*2 + (n-i)*3 <= k:
        print(i)
        exit()