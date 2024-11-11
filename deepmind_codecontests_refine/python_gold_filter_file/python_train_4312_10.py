
n = int(input())

x = list(map(int, input().split()))


x = [sorted(x[i:i+2]) for i in range(n-1)]


for c,d in x:
    for a,b in x:
        if a < c < b <d:
            print("yes")
            exit()



print("no")

