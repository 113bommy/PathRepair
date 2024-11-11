H,W=map(int,input().split())
if H == 1 or W == 1:
    print(1)
else:
    print(W*(H//2)+H%2*(W//2+W%2))