for _ in range(int(input())):
    s = input().split()
    l, r = int(s[0]), int(s[1])
    lrh = (r-l+1)//2
    if l == r:
        print(l if l%2 == 0 else -1*l)
    elif l%2 == r%2:
        print(-1*(lrh+l) if l%2 == 1 else lrh+l)
    else:
        print(lrh if r%2 == 0 else -1*lrh)
