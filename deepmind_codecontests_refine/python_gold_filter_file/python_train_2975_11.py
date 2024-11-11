x1, y1 = map(int, input().split())
x2, y2 = map(int, input().split())
x3, y3 = map(int, input().split())

answer = []

answer.append([(x2 - x1) + x3, (y3 - y1) + y2])
answer.append([x1 - (x3 - x2), y2 + (y1 - y3)])
answer.append([x1 + (x3 - x2), y3 - (y2 - y1)])

print(3)
for i in answer:
    print(*i)
