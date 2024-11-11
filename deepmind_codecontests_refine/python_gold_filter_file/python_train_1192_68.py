
n = input()
s = str(input())
k = 'qwertyuiopasdfghjkl;zxcvbnm,./'
l = []
if n == 'R' or n == 'r' and len(s) <= 100:
    for i in range(len(s)):
        for j in range(len(k)):
            if s[i] == k[j]:
                l.append(k[j-1])
                rs = ''.join(l)
elif n == 'L' or n == 'l' and len(s) <= 100:
    for i in range(len(s)):
        for j in range(len(k)-1):
            if s[i] == k[j]:
                l.append(k[j+1])
                rs = ''.join(l)
print(rs)
