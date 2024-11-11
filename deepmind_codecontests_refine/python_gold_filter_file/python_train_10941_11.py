ones = 3 * [1000000]
doubles = 3 * [1000000]
triple = 1000000
for i in range(int(input())):
    x = list(input().split())
    if len(x[1]) == 3 and int(x[0]) < triple:
        triple = int(x[0])
    elif len(x[1]) == 2:
        if (x[1] == 'AB' or x[1] == 'BA') and int(x[0]) < doubles[0]:
            doubles[0] = int(x[0])
        elif (x[1] == 'BC' or x[1] == 'CB') and int(x[0]) < doubles[1]:
            doubles[1] = int(x[0])
        elif (x[1] == 'AC' or x[1] == 'CA') and int(x[0]) < doubles[2]:
            doubles[2] = int(x[0])
    else:
        if x[1] == 'A' and int(x[0]) < ones[0]:
            ones[0] = int(x[0])
        elif x[1] == 'B' and int(x[0]) < ones[1]:
            ones[1] = int(x[0])
        elif x[1] == 'C' and int(x[0]) < ones[2]:
            ones[2] = int(x[0])
ans = min(triple, sum(doubles[:2]), sum(doubles[1:]), doubles[0] + doubles[-1], doubles[0] + ones[2],
          doubles[1] + ones[0], doubles[2] + ones[1], sum(ones))
if ans == 1000000:
    print(-1)
else:
    print(ans)
