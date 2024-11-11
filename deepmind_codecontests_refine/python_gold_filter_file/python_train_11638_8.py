N , K = map(int, input().split())
has = set()
for _ in range(K):
    d = int(input())
    has |= set(map(int, input().split()))
print(N - len(has))