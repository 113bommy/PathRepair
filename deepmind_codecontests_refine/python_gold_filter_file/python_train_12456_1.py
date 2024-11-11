n=int(input())
ar=list(map(int,input().split()))
for i in range(n):
    if ar[ar[ar[i]-1]-1]==i+1:
        print("YES")
        break
else:
    print("NO")
        