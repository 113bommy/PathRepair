n = list(input())

for i in n:
    if n.count(i)%2 != 0:
        print("No")
        exit()
print("Yes")


