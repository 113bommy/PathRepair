n = int(input())

s = set()
for _ in range(n):
    inst = input().split()
    if inst[0] == "insert":
        s.add(inst[1])
    else:
        if inst[1] in s:
            print("yes")
        else:
            print("no")