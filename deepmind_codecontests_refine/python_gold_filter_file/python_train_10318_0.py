n = int(input())
arr = list(map(int, input().split()))
count = [0]*101
unique = 0
multiple = 0
answer = ''
for i in range(n):
    count[arr[i]] += 1
for i in range(1, len(count)):
    if count[i] == 1:
        unique += 1
    elif count[i] > 2:
        multiple += 1
if unique % 2 == 0:
    multi = 0
    for j in range(n):
        if count[arr[j]] == 1:
            if multi == 0:
                answer += 'A'
                multi = 1
            elif multi == 1:
                answer += 'B'
                multi = 0
        elif count[arr[j]] > 1:
            answer += 'A'
else:
    if multiple == 0:
        answer = 'NO'
    else:
        put = False
        multi = 0
        for j in range(n):
            if count[arr[j]] == 1:
                if multi == 0:
                    answer += 'A'
                    multi = 1
                elif multi == 1:
                    answer += 'B'
                    multi = 0
            elif count[arr[j]] == 2:
                answer += 'A'
            elif count[arr[j]] > 2:
                if not put:
                    answer += 'B'
                    put = True
                else:
                    answer += 'A'
if answer == 'NO':
    print(answer)
else:
    print('YES')
    print(answer)
