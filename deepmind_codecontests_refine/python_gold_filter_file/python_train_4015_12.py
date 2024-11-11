t = int(input())
s = input().replace('W', ' ').split()
print(len(s))
for i in s:
    print(len(i), end= ' ')