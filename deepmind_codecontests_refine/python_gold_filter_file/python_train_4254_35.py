N, M = map(int, input().split())
cnt = [True]*N
for _ in range(M):
    a, b = map(int, input().split())
    cnt[a-1] = not cnt[a-1]; cnt[b-1] = not cnt[b-1];
print('YES' if all(cnt) else 'NO')