H,W = map(int,input().split())
mas = [list(input()) for i in range(H)]
new_mas = [row for row in mas if "#" in row]
new_mas2 = [column for column in list(zip(*new_mas)) if "#" in column]
for i in list(zip(*new_mas2)):
    for j in i:
        print(j,end="")
    print()
