s = input()
m = int(input())

c = []


for i in range(len(s)):
    for k in range(1,m+1):
        c.append(s[i:i+k])

b = sorted(list(set(c)))


print(b[m-1])
