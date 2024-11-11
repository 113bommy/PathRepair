D = int(input())
C = list(map(int, input().split()))
S = [list(map(int, input().split())) for _ in range(D)]
ans = [(i%26)+1 for i in range(1,D+1)]
for i in ans:
    print(i)