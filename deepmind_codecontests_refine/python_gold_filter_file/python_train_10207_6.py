while True:
    h,w = map(int,input().split())
    if h == w and h == 0:
        break
    for i in range(h):
        print("#"*w)
    print("")
