n = int(input())
li = list(map(int, input().strip().split()))
selected = [False]*n
li.sort()
inc = []
dec = []
for i in range(0, n):
    if i < n-2 and li[i] == li[i+1] and li[i+1] == li[i+2]:
        print("No")
        break
    else:
        # Increasing
        if li[i] == li[i-1]:
            continue
        if selected[i] == False:
            inc.append(li[i])
            selected[i] = True
else:
    for i in range(n-1, -1, -1):
        if selected[i] == False:
            dec.append(li[i])
    print("Yes")
    print(len(inc))
    for num in inc:
        print(num, end=' ')
    print()
    print(len(dec))
    for num in dec:
        print(num, end=' ')

