NUM = int(input())
ans = []
for _ in range(NUM):
    line = input()
    a, b, c= line.count("A"), line.count("B"), line.count("C")
    if b == (a + c):
        ans.append("Yes")
    else :
        ans.append("No")
for i in ans:
    print(i)
