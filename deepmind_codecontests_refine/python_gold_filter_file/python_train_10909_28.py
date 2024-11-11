N = int(input())
S = input()

count = 0
for i in range(1000):
    password = str(i).zfill(3)
    j = 0
    for s in S:
        if s == password[j]:
            j += 1
            if j == 3:
                count += 1
                break
print(count)