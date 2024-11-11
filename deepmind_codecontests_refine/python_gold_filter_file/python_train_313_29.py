while 1:
    (H,W) = [int(i) for i in input().split()]
    if H==W==0:
        break
    for i in range(H):
        for j in range(W):
            if (i+j)%2==0: print('#',end="")
            else: print('.',end="")
        print('')
    print('')
