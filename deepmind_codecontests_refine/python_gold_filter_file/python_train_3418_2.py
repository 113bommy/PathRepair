c = [list(map(int,input().split())) for i in range(3)]
if all((c[0][i+1] - c[0][i] == c[1][i+1] - c[1][i] == c[2][i+1] - c[2][i] for i in range(2))):
    print("Yes")
else:
    print("No")