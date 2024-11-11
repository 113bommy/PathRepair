H, W = map(int, input().split())
a = [list(input()) for i in range(H)]
a = list(zip(*[i for i in a if "#" in i]))
a = list(zip(*[i for i in a if "#" in i]))
for i in range(len(a)):
    print("".join(a[i]))