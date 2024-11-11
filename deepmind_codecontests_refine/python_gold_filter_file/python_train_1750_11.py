H, W, N = map(int, input().split())
sr, sc = map(int, input().split())
S = input()
T = input()

left = 1
right = W
bottom = 1
top = H

if S[-1] == 'L':
    left += 1
elif S[-1] == 'R':
    right -= 1
elif S[-1] == 'U':
    bottom += 1
elif S[-1] == 'D':
    top -= 1

for i in range(N - 1)[:: -1]:
    if T[i] == 'L':
        right = min(W, right + 1)
    elif T[i] == 'R':
        left = max(1, left - 1)
    elif T[i] == 'U':
        top = min(H, top + 1)
    elif T[i] == 'D':
        bottom = max(1, bottom - 1)

    if S[i] == 'L':
        left += 1
    elif S[i] == 'R':
        right -= 1
    elif S[i] == 'U':
        bottom += 1
    elif S[i] == 'D':
        top -= 1

    if left > right or bottom > top:
        print('NO')
        break
else:
    if left <= sc <= right and bottom <= sr <= top:
        print('YES')
    else:
        print('NO')

