ref = [int(j) for j in input().split(',')]
freq = 1000 * [0]
for j in range(len(ref)):
    freq[ref[j] - 1] = 1
p = 0
List = []
while p < 1000:
    if freq[p] == 1:
        sp, count = p + 1, 0
        while sp < 1000:
            if freq[sp] == 1:
                count += 1
                sp += 1
            else:
                break
        List.append([str(p + 1), str(sp)])
        p = sp
    else:
        p += 1
for j in range(len(List) - 1):
    if List[j][0] == List[j][1]:
        print(end = List[j][0])
    else:
        print(end = List[j][0] + '-' + List[j][1])
    print(end = ',')
n = len(List) - 1
if List[n][0] == List[n][1]:
    print(List[n][0])
else:
    print(List[n][0] + '-' + List[n][1])
