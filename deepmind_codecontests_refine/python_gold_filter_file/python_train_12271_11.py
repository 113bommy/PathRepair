N=int(input())

for i in range(N):
    hens=list(map(int, input().split()))
    hens.sort()
    if hens[0]**2+hens[1]**2==hens[2]**2:
        print("YES")
    else:
        print("NO")