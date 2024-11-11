N=int(input())
H=list(map(int,input().split()))
a=0
for i in range(N-1):
    if a<H[i]:
        a=H[i]
    if a-1>H[i+1]:
        print("No")
        break
else:
    print("Yes")