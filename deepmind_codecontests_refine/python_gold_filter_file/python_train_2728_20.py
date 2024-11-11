t=int(input())
for i in range(t):
    t=True
    x=input()
    x=list(map(int,input().split(" ")))
    for i in range (len(x)-1):
        if abs(x[i]-x[i+1])>1:
            print("YES")
            print(i+1,i+2)
            t=False
            break
    if t:
        print("NO")

