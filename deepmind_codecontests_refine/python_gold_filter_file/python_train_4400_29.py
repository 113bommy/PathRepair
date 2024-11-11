n = int(input())
ls = list(map(int, input().split()))
for i in range(1, n+1):
    print(ls.index(i)+1, end=" ")
