x, y = map(int, input().split())
if abs(y) >= abs(x) and y != 0:
    if y > 0:
        ans = 2*(2*y-1)
    else:
        ans = 4*abs(y)
    if x == y:
        print(ans-1)
    else:
        print(ans)
elif abs(x) >= abs(y) and x != 0:
    if x > 0:
        if x == 1:
            ans = 0
        else:
            ans = 4*x-3
    else:
        ans = 4*abs(x)-1
    if (x < 0 and x == -y) or(x > 0 and y == -abs(abs(x)-1)):
        print(max(ans-1, 0))
    else:
        print(ans)
else:
    print(0)