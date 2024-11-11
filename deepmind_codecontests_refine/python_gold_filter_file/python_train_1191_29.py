


n = int(input())

a = [int(i) for i in input().split()]

b = sorted(a)
count = 0
j = n - 1
rng = []
for i in range(0, n):
    if a[i] != b[i]:
        count += 1
        if count > 1:
            break
        while j > i:
            if a[j] != b[j]:
                break
            j -= 1

        a[i:j+1] = reversed(a[i:j+1])
        rng = [i+1, j+1]

if count == 1:
    print('yes')
    print(rng[0], rng[1])
else:
    if count == 0:
        print('yes')
        print(1, 1)
    else:
        print('no')

