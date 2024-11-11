n, s, count= int(input()), [], 1

for i in range(n):
    s.append(sum(list(map(int, input().split()))))
for i in range(1, len(s)):
    if s[i]> s[0]:
        count+=1
print(count)