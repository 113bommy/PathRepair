t = int(input())

for _ in range(t):
    s = input()
    l = len(s)
    if(l%2 != 0):
        print("NO")
        continue
    s1 = s[:l//2]
    s2 = s[l//2:]
    if(s1 == s2):
        print("YES")
        continue
    print("NO")