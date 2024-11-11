string = input()
look = 'CODEFORCES'
idx = 0
found = False

for i in range(len(string)):
    for j in range(i, len(string) + 1):
        left = string[:i] + string[j:]
        if left == look:
            print("YES")
            exit(0)

print("NO")
