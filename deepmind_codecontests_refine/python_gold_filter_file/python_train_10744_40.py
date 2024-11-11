t=int(input())
for _ in range(t):
    li=list(map(int,input().split()))
    li.sort()
    if li[0]+li[1]>=li[2]-1:
        print("Yes")
    else:
        print("No")
