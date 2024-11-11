while True:
    H,W = map(int, input().split())
    if H == W == 0: break
    print("#"*W)
    print(("#"+"."*(W-2)+"#\n")*(H-2),end="")
    print("#"*W+"\n")
