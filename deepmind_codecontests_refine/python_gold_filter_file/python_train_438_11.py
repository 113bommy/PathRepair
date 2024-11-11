# print((-1337)%3)
t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int,input().split()))
    y = []
    for i in range(n):
        y.append((i%n+a[i%n])%n)
    if(len(list(set(y)))==len(y)):
        print("YES")
    else:
        print("NO")