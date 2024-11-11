t = int(input())
answer = []
for i in range(t):
    n = int(input())
    string = ""
    dict = {}
    for j in range(n):
        string += input()
    for index in range(len(string)):
        if string.index(string[index]) == index:
            dict[string[index]] = 1
        else:
            dict[string[index]] += 1
    for value in dict.values():
        if value % n != 0:
            answer.append("NO")
            break
    else:
        answer.append("YES")
for i in answer:
    print(i)
