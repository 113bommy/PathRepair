n, k = map(int, input().split())
try:
    a = sorted(map(int, input().split()), reverse=True)[k - 1] 
    print(0, a)
except:
    print(-1)
