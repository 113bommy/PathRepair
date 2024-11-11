b=list(input())
b=list(map(int,b))
for i in range(len(b)):
    if b[i]==1:
        if b[i:].count(0)>5:
            print("yes")
            exit()
        else:
            print("no")
            exit()
print("no")