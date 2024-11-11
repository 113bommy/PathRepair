n = int(input())
x = list(input())
a = list(map(int, input().split()))
a = {str(i + 1): str(a[i]) for i in range(9)}

f = False

for i in range(n):
    if x[i] < a[x[i]]:
        for j in range(i, n):
            if x[j] <= a[x[j]]:
                x[j] = a[x[j]]
            else:
                break
        break

print(''.join(x))
