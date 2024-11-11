while 1:
    H,W = map(int,input().split())
    if (H,W) == (0,0):
        break
    for _ in range(H):
        print('#'*W)
    print()
