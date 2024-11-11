while 1:
    (H, W) = [int(num) for num in input().split()]
    if H==W==0:
        break
    print('#'*W)
    for i in range(H-2):
        print('#'+'.'*(W-2)+'#')
    print('#'*W)
    print('')

