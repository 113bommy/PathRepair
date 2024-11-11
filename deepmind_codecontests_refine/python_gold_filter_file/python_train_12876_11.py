x = input()
s = set(map(int, input().split()))

if 0 in s:
    print(len(s)-1)
else:
    print(len(s))
