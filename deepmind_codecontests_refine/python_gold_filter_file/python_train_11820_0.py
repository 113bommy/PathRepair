n=int(input())
x = sorted(set(list(map(int, input().split(" ")))))
for i in range(len(x)-2):
    if x[i+2]-x[i]==2:
        print("YES")
        exit()
print("NO")