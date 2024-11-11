l, r = map(int, input().split())
if r == l + 1 or r == l:
    print(-1)
elif l%2 == 0:
    print(l, l+1, l+2)
elif abs(r - l) >= 3:
    print(l+1, l+2, l+3)
else:
    print(-1)