n, k = map(int, input().split())
seq = str(input())

used = [False for _ in range(n)]

counter = 0
i = 0
stack = []

while counter != k:
    if seq[i] == '(':
        stack.append(i)
    else:
        used[stack.pop()] = True
        used[i] = True
        counter += 2

    i += 1

arr = ''.join([seq[i] if used[i] else '' for i in range(n)])
print(arr)