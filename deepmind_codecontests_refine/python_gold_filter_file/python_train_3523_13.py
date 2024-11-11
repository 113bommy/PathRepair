H,W = map(int,input().split())
N = int(input())
A = list(map(int,input().split()))
check = []

for i,v in enumerate(A):
    check += [i + 1] * v

for i in range(H):
    if i % 2 ==0:
        print(*check[i*W:(i+1)*W])
    else:
        print(*check[i*W:(i+1)*W][::-1])