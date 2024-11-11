a = [int(x) for x in input().split()]

ans = 2*(a[0]//2 + a[3]//2 + a[4]//2) + 3*(1 & a[0] & a[3] & a[4])
if a[0] and a[3] and a[4]:
    ans = max(ans, 2*((a[0]-1)//2 + (a[3]-1)//2 + (a[4]-1)//2) + 3)

print(int(ans + a[1]))
