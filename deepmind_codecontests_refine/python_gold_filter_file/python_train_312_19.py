while True:
    h,w = map(int,input().split())
    if h == w == 0:
        break;
    first="#."
    for i in range(h):
        print(first*(w//2)+first[0]*(w%2))
        first=first[1]+first[0]

    print()