s, m = map(int, input().rstrip().split(" "))
if s <m:
    print(-1)
elif s == m:
    print(m)
else:
    mi = s//2 + s%2
    if mi + m - mi%m > s+1:
        print(-1)
    else:
        if mi%m==0:
            print(mi)
        else:
            print(mi + m - mi%m)
