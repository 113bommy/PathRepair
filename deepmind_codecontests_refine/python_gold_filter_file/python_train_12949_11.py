x = int(input())
ve = list(map(int , input().split()))
mn = min(int(i) for i in ve)
for i in range(0 , x ):
    if ve[i] % mn != 0:
        print("-1")
        exit()

print(mn)