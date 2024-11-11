S = str(input())
for i in range(8):
    word = S[:i]+S[-7:][i:]
    if word == "keyence":
        print("YES")
        exit()
print("NO")