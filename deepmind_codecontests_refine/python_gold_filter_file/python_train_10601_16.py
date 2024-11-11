X,Y = map(int,input().split())
ans = 0
while Y>=X:
    ans += 1
    X*=2
print(ans)
