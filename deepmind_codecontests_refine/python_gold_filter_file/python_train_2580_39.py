H = int(input())
W = int(input())
N = int(input())

a = max(H, W)
print((N+a-1)//a)