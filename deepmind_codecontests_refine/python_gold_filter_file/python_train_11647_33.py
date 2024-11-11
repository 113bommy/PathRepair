import string

S = input()

for a in string.ascii_lowercase:
    pre = -1
    for i, s in enumerate(S):
        if s == a:
            if pre != -1 and i - pre <= 2:
                print(pre+1, i+1)
                exit()
            else:
                pre = i

print(-1, -1)
