t = int(input())
for i in range(t):
    s = input()
    l =len(s)
    rem = []
    ans = 0
    skip = 0
    for j in range(l-2):
        if skip > 0:
            skip -= 1
            continue
        if j <= l-5  and s[j:j+5] == 'twone':
            ans += 1
            rem.append(j+3)
            skip = 4
        elif s[j:j+3] == 'two':
            ans += 1
            rem.append(j+2)
        elif s[j:j+3] == 'one':
            ans += 1
            rem.append(j+2)
    print(ans)
    if ans == 0:
        print()
    else:
        for j in rem:
            print(j, end = ' ')
        print()