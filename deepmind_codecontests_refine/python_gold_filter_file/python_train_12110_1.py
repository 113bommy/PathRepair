cases,  m = map(int, input().split())

bests = [0]*m
students = []
while cases:
    cases -= 1
    arr = list(map(int, list(input())))
    students.append(arr)

    for i, n in enumerate(arr):
        if n > bests[i]:
            bests[i] = n
ans = 0
for student in students:
    for i in range(m):
        if student[i] >= bests[i]:
            ans += 1
            break

print(ans)
# print(bests)
# print(students)