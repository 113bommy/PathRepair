n = int(input())
st = input()
lst = list(map(int, input().split()))

minn = float("INF")
yes = False
for i in range(n-1):
    if st[i] == "R" and st[i+1] == "L":
        yes = True
        minn = min(minn, (lst[i+1] - lst[i])//2)
        
if not yes: print(-1)
else: print(minn+1-1)
