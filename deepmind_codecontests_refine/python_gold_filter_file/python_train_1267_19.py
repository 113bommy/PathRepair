n,x,y = map(int,input().split())
a = list(map(int,input().split()))
for i in range(n):
    if a[i] == min(a[max(0,i-x):min(n,i+y+1)]):
        print(i+1)
        break
