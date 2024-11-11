N = int(input())
an = list(map(int,input().split()))
ave  = round((sum(an)/N),0)
ans = 0

for i in an:
    ans += (i-ave)**2

print(int(ans))